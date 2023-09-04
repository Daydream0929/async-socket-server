#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>
#include <vector>

class ThreadPool {
public:
    ThreadPool(int numThreads);
    
    template <typename Func, typename... Args>
    void enqueue(Func&& func, Args&&... args);
    
    ~ThreadPool();

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};

// 模板函数的完整定义放在头文件中
template <typename Func, typename... Args>
void ThreadPool::enqueue(Func&& func, Args&&... args) {
    auto task = std::bind(std::forward<Func>(func), std::forward<Args>(args)...);
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        if (stop)
            throw std::runtime_error("enqueue on stopped ThreadPool");
        tasks.emplace(task);
    }
    condition.notify_one();
}
#endif // THREADPOOL_H
