#include "thread_pool.h"

void taskFunction(int i) {
    std::cout << "Task " << i << " is being processed by thread " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Task " << i << " is done." << std::endl;
}

int main() {
    ThreadPool pool(4);

    for (int i = 0; i < 8; ++i) {
        pool.enqueue(taskFunction, i);
    }

    std::this_thread::sleep_for(std::chrono::seconds(3));

    return 0;
}
