#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>

using namespace std;

#define N 4
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + 4) % N
#define RIGHT (phnum + 1) % N

class Monitor {
public:
    Monitor() {
        state.resize(N, THINKING);
        phcond.resize(N);
    }

    void test(int phnum) {
        if (state[(phnum + 1) % N] != EATING && state[(phnum + 4) % N] != EATING && state[phnum] == HUNGRY) {
            state[phnum] = EATING;
            phcond[phnum].notify_one();
        }
    }

    void take_fork(int phnum) {
        unique_lock<mutex> lock(condLock);
        state[phnum] = HUNGRY;
        test(phnum);
        if (state[phnum] != EATING) {
            phcond[phnum].wait(lock);
        }
    }

    void put_fork(int phnum) {
        unique_lock<mutex> lock(condLock);
        state[phnum] = THINKING;
        test(RIGHT);
        test(LEFT);
    }

private:
    vector<int> state;
    vector<condition_variable> phcond;
    mutex condLock;
};

Monitor phil_object;
int times = 200;

void philosopher(int phnum) {
    int c = 0;
    while (c < times) {
        cout << "Philosopher " << phnum + 1 << " is thinking..." << endl;
        this_thread::sleep_for(chrono::seconds(3));
        cout << "Philosopher " << phnum + 1 << " is waiting..." << endl;
        phil_object.take_fork(phnum);
        cout << "Philosopher " << phnum + 1 << " is eating..." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        phil_object.put_fork(phnum);
        cout << "Philosopher " << phnum + 1 << " eated..." << endl;
        c++;
    }
}

int main() {
    srand(time(0));
    vector<thread> threads(N);

    for (int i = 0; i < N; i++) {
        threads[i] = thread(philosopher, i);
    }

    for (int i = 0; i < N; i++) {
        threads[i].join();
    }

    return 0;
}
