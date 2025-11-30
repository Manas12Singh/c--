#include <iostream>
#include <vector>
#include <chrono>
#include "xthread.hpp"

int main()
{
    using namespace std::chrono_literals;
    std::cout << "xthread demo start\n";
    xthr::Semaphore sem(0);
    xthr::Thread t1([&]
                    {
        xthr::sleep_for(100ms);
        sem.release(3); });
    for (int i = 0; i < 3; ++i)
        sem.acquire();
    t1.join();
    xthr::ThreadPool pool(4);
    auto f1 = pool.submit([]
                          { return 21 * 2; });
    auto f2 = pool.submit([&]
                          {
        xthr::sleep_for(150ms);
        return std::string("ok"); });
    std::cout << "f1=" << f1.get() << ", f2=" << f2.get() << "\n";
    auto f3 = pool.submit([&]
                          { std::cout << "hello from worker\n"; });
    f3.get();
    auto f4 = pool.submit([&]
                          {
        std::cout << "hello from worker" << std::endl;
        std::vector<int> input(10);
        for (int i = 0; i < 10; ++i)
            input[i] = i;
        std::vector<int> output(10);
        std::vector<xthr::SimpleFuture<void>> futs;
        for (int i = 0; i < 10; ++i)
        {
            futs.push_back(pool.submit([i, &output]
                                       { output[i] = i * i; }));
        }
        for (auto &f : futs)
            f.get();
        std::cout << "squares: ";
        for (int v : output)
            std::cout << v << ' ';
        std::cout << "\n";
        for (int v : output)
            std::cout << "xthread demo done\n";
        return 0; });
    f4.get();
    return 0;
}
