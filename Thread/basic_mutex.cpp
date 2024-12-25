// Example of using a mutex to protect a shared resource.

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // mutex for critical section
int shared_data = 0; // shared data

void increment(int n) {
    for (int i = 0; i < n; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // lock mutex with automatic unlock at the end of the scope
        ++shared_data;
        std::cout << "Thread " << std::this_thread::get_id() 
                  << " incremented shared_data to " << shared_data << std::endl;
    }
}

int main() {
    std::thread t1(increment, 5);
    std::thread t2(increment, 20);

    t1.join();
    t2.join();

    std::cout << "Final value of shared_data: " << shared_data << std::endl;
    return 0;
}

