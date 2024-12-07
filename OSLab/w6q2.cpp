#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

#define BUFFER_SIZE 2

class Buffer
{
public:
    Buffer() : count(0), in(0), out(0), stop(false)
    {
        buffer.resize(BUFFER_SIZE);
    }

    void produce()
    {
        while (!stop)
        {
            int item = rand() % 100;

            unique_lock<mutex> lock(mtx);
            cv_empty.wait(lock, [this]()
                          { return count != BUFFER_SIZE; });

            buffer[in] = item;
            in = (in + 1) % BUFFER_SIZE;
            count++;
            cout << "Producer produced: " << item << " (buffer count: " << count << ")" << endl;

            cv_full.notify_one();
            lock.unlock();
            sleep(4);
        }
    }

    void consume()
    {
        while (!stop)
        {
            unique_lock<mutex> lock(mtx);
            cv_full.wait(lock, [this]()
                         { return count != 0; });

            int item = buffer[out];
            out = (out + 1) % BUFFER_SIZE;
            count--;
            cout << "Consumer consumed: " << item << " (buffer count: " << count << ")" << endl;

            cv_empty.notify_one();
            lock.unlock();
            sleep(rand() % 6 + 1);
        }
    }

    void stopProcessing()
    {
        stop = true;
    }

private:
    vector<int> buffer;
    int count;
    int in, out;
    bool stop;
    mutex mtx;
    condition_variable cv_empty, cv_full;
};

int main()
{
    cout << "Enter q to quit" << endl;
    Buffer buffer;

    srand(time(NULL));

    thread producer_thread(&Buffer::produce, &buffer);
    thread consumer_thread(&Buffer::consume, &buffer);

    if (cin.get() == 'q')
        buffer.stopProcessing();

    producer_thread.join();
    consumer_thread.join();

    return 0;
}
