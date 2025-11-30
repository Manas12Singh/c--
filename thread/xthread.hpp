/*
  xthread.hpp — a tiny cross‑platform C++17 thread library without <thread>/<mutex>/<condition_variable>/<future>
  -----------------------------------------------------------------------------------------------
  OS backends only:
    • Windows: WinAPI (CreateThread, CRITICAL_SECTION, CONDITION_VARIABLE, Semaphore)
    • POSIX  : pthreads (pthread_create, pthread_mutex, pthread_cond), sem_* where available

  Features (header‑only):
    • Mutex, LockGuard, CondVar (condition variable)
    • Semaphore (counting) implemented portably with Mutex+CondVar (no OS semaphore required)
    • Thread (RAII joinable thread)
    • SafeQueue<T> (blocking queue)
    • SimpleFuture<T> (minimal future/promise replacement) — NO <future>
    • ThreadPool (fixed size) with submit() returning SimpleFuture<R>
    • sleep_for utility

  Notes:
    - Uses only standard containers/functional but NO std threading primitives.
    - Exceptions inside tasks are captured and rethrown from SimpleFuture::get().
    - This is intentionally minimal; extend as needed (timers, rwlock, etc.).

  Usage:
    #define XTHREAD_DEMO 1
    #include "xthread.hpp"
*/

#pragma once
#include <cstdint>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <functional>
#include <queue>
#include <vector>
#include <stdexcept>
#include <utility>
#include <chrono>
#include <string>
#include <memory>
#include <type_traits>
// -------------------------- Platform selection --------------------------- //
#if defined(_WIN32)
#define XTHREAD_WINDOWS 1
#include <windows.h>
#elif defined(__unix__) || defined(__APPLE__)
#define XTHREAD_POSIX 1
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#else
#error "Unsupported platform"
#endif

    namespace xthr
{

    // ------------------------------- sleep_for -------------------------------- //
    inline void sleep_for(std::chrono::milliseconds ms)
    {
#if defined(XTHREAD_WINDOWS)
        ::Sleep(static_cast<DWORD>(ms.count()));
#else
        struct timespec ts;
        ts.tv_sec = static_cast<time_t>(ms.count() / 1000);
        ts.tv_nsec = static_cast<long>((ms.count() % 1000) * 1000000L);
        while (nanosleep(&ts, &ts) == -1 && errno == EINTR)
        {
        }
#endif
    }

    // -------------------------------- Mutex ---------------------------------- //
    class Mutex
    {
    public:
        Mutex()
        {
#if defined(XTHREAD_WINDOWS)
            InitializeCriticalSection(&cs_);
#else
            pthread_mutexattr_t attr;
            pthread_mutexattr_init(&attr);
            pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_NORMAL);
            if (pthread_mutex_init(&mtx_, &attr) != 0)
                throw std::runtime_error("pthread_mutex_init failed");
            pthread_mutexattr_destroy(&attr);
#endif
        }
        ~Mutex()
        {
#if defined(XTHREAD_WINDOWS)
            DeleteCriticalSection(&cs_);
#else
            pthread_mutex_destroy(&mtx_);
#endif
        }
        void lock()
        {
#if defined(XTHREAD_WINDOWS)
            EnterCriticalSection(&cs_);
#else
            if (pthread_mutex_lock(&mtx_) != 0)
                throw std::runtime_error("pthread_mutex_lock failed");
#endif
        }
        void unlock()
        {
#if defined(XTHREAD_WINDOWS)
            LeaveCriticalSection(&cs_);
#else
            if (pthread_mutex_unlock(&mtx_) != 0)
                throw std::runtime_error("pthread_mutex_unlock failed");
#endif
        }
        // non-copyable
        Mutex(const Mutex &) = delete;
        Mutex &operator=(const Mutex &) = delete;

#if defined(XTHREAD_WINDOWS)
        CRITICAL_SECTION *native() { return &cs_; }
#else
        pthread_mutex_t *native() { return &mtx_; }
#endif

    private:
#if defined(XTHREAD_WINDOWS)
        CRITICAL_SECTION cs_{};
#else
        pthread_mutex_t mtx_{};
#endif
    };

    class LockGuard
    {
    public:
        explicit LockGuard(Mutex &m) : m_(m) { m_.lock(); }
        ~LockGuard() { m_.unlock(); }
        LockGuard(const LockGuard &) = delete;
        LockGuard &operator=(const LockGuard &) = delete;

    private:
        Mutex &m_;
    };

    // ---------------------------- Condition Variable -------------------------- //
    class CondVar
    {
    public:
        CondVar()
        {
#if defined(XTHREAD_WINDOWS)
            InitializeConditionVariable(&cv_);
#else
            if (pthread_cond_init(&cv_, nullptr) != 0)
                throw std::runtime_error("pthread_cond_init failed");
#endif
        }
        ~CondVar()
        {
#if defined(XTHREAD_POSIX)
            pthread_cond_destroy(&cv_);
#endif
        }
        void wait(Mutex &m)
        {
#if defined(XTHREAD_WINDOWS)
            SleepConditionVariableCS(&cv_, m.native(), INFINITE);
#else
            if (pthread_cond_wait(&cv_, m.native()) != 0)
                throw std::runtime_error("pthread_cond_wait failed");
#endif
        }
        template <class Rep, class Period>
        bool wait_for(Mutex &m, const std::chrono::duration<Rep, Period> &d)
        {
#if defined(XTHREAD_WINDOWS)
            DWORD ms = static_cast<DWORD>(std::chrono::duration_cast<std::chrono::milliseconds>(d).count());
            return SleepConditionVariableCS(&cv_, m.native(), ms) != 0; // true if signaled
#else
            using namespace std::chrono;
            auto ns = duration_cast<nanoseconds>(d);
            struct timespec ts;
            clock_gettime(CLOCK_REALTIME, &ts);
            long nsec = ts.tv_nsec + static_cast<long>(ns.count() % 1000000000LL);
            ts.tv_sec += static_cast<time_t>(ns.count() / 1000000000LL);
            if (nsec >= 1000000000L)
            {
                ts.tv_sec += 1;
                nsec -= 1000000000L;
            }
            ts.tv_nsec = nsec;
            int rc = pthread_cond_timedwait(&cv_, m.native(), &ts);
            return rc == 0;
#endif
        }
        void notify_one()
        {
#if defined(XTHREAD_WINDOWS)
            WakeConditionVariable(&cv_);
#else
            pthread_cond_signal(&cv_);
#endif
        }
        void notify_all()
        {
#if defined(XTHREAD_WINDOWS)
            WakeAllConditionVariable(&cv_);
#else
            pthread_cond_broadcast(&cv_);
#endif
        }

    private:
#if defined(XTHREAD_WINDOWS)
        CONDITION_VARIABLE cv_{};
#else
        pthread_cond_t cv_{};
#endif
    };

    // ------------------------------- Semaphore -------------------------------- //
    // Portable counting semaphore implemented with Mutex+CondVar.
    class Semaphore
    {
    public:
        explicit Semaphore(int initial = 0) : count_(initial) {}
        void release(int n = 1)
        {
            LockGuard lg(m_);
            count_ += n;
            cv_.notify_all();
        }
        void acquire()
        {
            m_.lock();
            while (count_ == 0)
                cv_.wait(m_);
            --count_;
            m_.unlock();
        }
        template <class Rep, class Period>
        bool try_acquire_for(const std::chrono::duration<Rep, Period> &d)
        {
            m_.lock();
            bool ok = true;
            auto end = std::chrono::steady_clock::now() + d;
            while (count_ == 0)
            {
                auto now = std::chrono::steady_clock::now();
                if (now >= end)
                {
                    ok = false;
                    break;
                }
                // Wait in small chunks to emulate timeout
                if (!cv_.wait_for(m_, std::chrono::milliseconds(5)))
                { /* spurious */
                }
            }
            if (ok)
                --count_;
            m_.unlock();
            return ok;
        }

    private:
        Mutex m_;
        CondVar cv_;
        int count_{};
    };

    // --------------------------------- Thread -------------------------------- //
    class Thread
    {
    public:
        using Func = std::function<void()>;

        Thread() = default;
        explicit Thread(Func fn) { start(std::move(fn)); }
        ~Thread() { /* do not auto-join to avoid deadlocks; caller manages */ }

        void start(Func fn)
        {
            if (running_)
                throw std::runtime_error("Thread already running");
            fn_ = std::make_shared<Func>(std::move(fn));
#if defined(XTHREAD_WINDOWS)
            handle_ = CreateThread(nullptr, 0, &Thread::trampoline, fn_.get(), 0, &tid_);
            if (!handle_)
                throw std::runtime_error("CreateThread failed");
#else
            if (pthread_create(&tid_, nullptr, &Thread::trampoline, fn_.get()) != 0)
                throw std::runtime_error("pthread_create failed");
#endif
            running_ = true;
        }

        bool joinable() const { return running_; }

        void join()
        {
            if (!running_)
                return;
#if defined(XTHREAD_WINDOWS)
            WaitForSingleObject(handle_, INFINITE);
            CloseHandle(handle_);
            handle_ = nullptr;
#else
            pthread_join(tid_, nullptr);
#endif
            running_ = false;
            fn_.reset();
        }

        void detach()
        {
            if (!running_)
                return;
#if defined(XTHREAD_WINDOWS)
            CloseHandle(handle_);
            handle_ = nullptr; // thread continues detached
#else
            pthread_detach(tid_);
#endif
            running_ = false;
            fn_.reset();
        }

        Thread(const Thread &) = delete;
        Thread &operator=(const Thread &) = delete;
        Thread(Thread &&other) noexcept { move_from(std::move(other)); }
        Thread &operator=(Thread &&other) noexcept
        {
            if (this != &other)
            {
                cleanup();
                move_from(std::move(other));
            }
            return *this;
        }

    private:
        void cleanup()
        {
            if (running_)
                detach();
        }
        void move_from(Thread &&o)
        {
#if defined(XTHREAD_WINDOWS)
            handle_ = o.handle_;
            o.handle_ = nullptr;
#endif
            tid_ = o.tid_;
            running_ = o.running_;
            fn_ = std::move(o.fn_);
            o.running_ = false;
        }
#if defined(XTHREAD_WINDOWS)
        static DWORD WINAPI trampoline(LPVOID p)
        {
            auto *fn = static_cast<Func *>(p);
            (*fn)();
            return 0;
        }
        HANDLE handle_ = nullptr;
        DWORD tid_ = 0;
#else
        static void *trampoline(void *p)
        {
            auto *fn = static_cast<Func *>(p);
            (*fn)();
            return nullptr;
        }
        pthread_t tid_{};
#endif
        bool running_ = false;
        std::shared_ptr<Func> fn_{}; // keep target alive until start returns
    };

    // -------------------------------- SafeQueue ------------------------------- //
    template <class T>
    class SafeQueue
    {
    public:
        void push(T v)
        {
            {
                LockGuard lg(m_);
                q_.push(std::move(v));
            }
            cv_.notify_one();
        }
        bool pop(T &out)
        { // blocking pop
            m_.lock();
            while (q_.empty() && !closed_)
                cv_.wait(m_);
            if (q_.empty())
            {
                m_.unlock();
                return false;
            }
            out = std::move(q_.front());
            q_.pop();
            m_.unlock();
            return true;
        }
        bool try_pop(T &out)
        { // non-blocking
            LockGuard lg(m_);
            if (q_.empty())
                return false;
            out = std::move(q_.front());
            q_.pop();
            return true;
        }
        void close()
        {
            {
                LockGuard lg(m_);
                closed_ = true;
            }
            cv_.notify_all();
        }
        bool closed() const { return closed_; }

    private:
        mutable Mutex m_;
        CondVar cv_;
        std::queue<T> q_;
        bool closed_ = false;
    };

    // ------------------------------- SimpleFuture ----------------------------- //
    template <class T>
    class SimpleFuture
    {
    public:
        SimpleFuture() = default;
        T get()
        {
            m_.lock();
            while (!ready_)
                cv_.wait(m_);
            m_.unlock();
            if (ex_)
                std::rethrow_exception(ex_);
            return std::move(value_);
        }
        bool valid() const { return state_set_; }

    private:
        template <class>
        friend class Promise;
        void set_value(T v)
        {
            LockGuard lg(m_);
            value_ = std::move(v);
            ready_ = true;
            state_set_ = true;
            cv_.notify_all();
        }
        void set_exception(std::exception_ptr e)
        {
            LockGuard lg(m_);
            ex_ = e;
            ready_ = true;
            state_set_ = true;
            cv_.notify_all();
        }
        mutable Mutex m_;
        CondVar cv_;
        bool ready_ = false;
        bool state_set_ = false;
        T value_{};
        std::exception_ptr ex_{};
    };

    template <>
    class SimpleFuture<void>
    {
    public:
        void get()
        {
            m_.lock();
            while (!ready_)
                cv_.wait(m_);
            m_.unlock();
            if (ex_)
                std::rethrow_exception(ex_);
        }
        bool valid() const { return state_set_; }

    private:
        template <class>
        friend class Promise;
        void set_value()
        {
            LockGuard lg(m_);
            ready_ = true;
            state_set_ = true;
            cv_.notify_all();
        }
        void set_exception(std::exception_ptr e)
        {
            LockGuard lg(m_);
            ex_ = e;
            ready_ = true;
            state_set_ = true;
            cv_.notify_all();
        }
        mutable Mutex m_;
        CondVar cv_;
        bool ready_ = false;
        bool state_set_ = false;
        std::exception_ptr ex_{};
    };

    // --------------------------------- Promise -------------------------------- //
    template <class T>
    class Promise
    {
    public:
        Promise() : fut_(std::make_shared<SimpleFuture<T>>()) {}
        SimpleFuture<T> get_future() { return *fut_; } // returns a copy (state is shared)
        void set_value(T v) { fut_->set_value(std::move(v)); }
        void set_exception(std::exception_ptr e) { fut_->set_exception(e); }

    private:
        std::shared_ptr<SimpleFuture<T>> fut_;
    };

    template <>
    class Promise<void>
    {
    public:
        Promise() : fut_(std::make_shared<SimpleFuture<void>>()) {}
        SimpleFuture<void>& get_future() { return *fut_; }
        void set_value() { fut_->set_value(); }
        void set_exception(std::exception_ptr e) { fut_->set_exception(e); }

    private:
        std::shared_ptr<SimpleFuture<void>> fut_;
    };

    // ------------------------------- ThreadPool -------------------------------- //
    class ThreadPool
    {
    public:
        explicit ThreadPool(std::size_t nthreads) { start(nthreads); }
        ~ThreadPool() { stop(); }

        ThreadPool(const ThreadPool &) = delete;
        ThreadPool &operator=(const ThreadPool &) = delete;

        template <class F, class... Args>
        auto submit(F &&f, Args &&...args)
        {
            using R = decltype(f(args...));
            using P = Promise<R>;

            auto task = std::make_shared<std::function<R()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));

            P prom;
            auto fut = prom.get_future();
            jobs_.push([task, prom]() mutable
                       {
      try {
        if constexpr (std::is_void<R>::value) { (*task)(); prom.set_value(); }
        else { auto r = (*task)(); prom.set_value(std::move(r)); }
      } catch (...) { prom.set_exception(std::current_exception()); } });
            return fut;
        }

        void stop()
        {
            if (stopping_)
                return;
            stopping_ = true;
            jobs_.close();
            for (auto &t : threads_)
                if (t.joinable())
                    t.join();
            threads_.clear();
        }

    private:
        void start(std::size_t n)
        {
            if (n == 0)
                n = 1;
            threads_.reserve(n);
            for (std::size_t i = 0; i < n; ++i)
            {
                threads_.emplace_back(Thread([this]
                                             { worker_loop(); }));
            }
        }
        void worker_loop()
        {
            for (;;)
            {
                std::function<void()> job;
                if (!jobs_.pop(job))
                    break; // queue closed and empty
                try
                {
                    job();
                }
                catch (...)
                { /* keep worker alive */
                }
            }
        }
        bool stopping_ = false;
        std::vector<Thread> threads_;
        SafeQueue<std::function<void()>> jobs_;
    };

} // namespace xthr