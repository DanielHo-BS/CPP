#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> dataQueue;
bool done = false;

void producer(int id, int numItems) {
    for (int i = 1; i <= numItems; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100 * id)); // 模擬不同生產速度
        {
            std::lock_guard<std::mutex> lock(mtx);
            dataQueue.push(i + id * 100); // each producer produces different data
            std::cout << "Producer " << id << " produced: " << i + id * 100 << std::endl;
        }
        cv.notify_one(); // notify one consumer
    }

    {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Producer " << id << " done." << std::endl;
    }
}

void consumer(int id) {
    while (true) {
        int data = 0;
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [] { return !dataQueue.empty() || done; }); // wait until dataQueue is not empty or done is true

            if (!dataQueue.empty()) {
                data = dataQueue.front();
                dataQueue.pop();
            } else if (done) {
                break; // if dataQueue is empty and done is true, exit the loop
            }
        }

        if (data != 0) {
            std::cout << "Consumer " << id << " consumed: " << data << std::endl;
        }
    }
    std::cout << "Consumer " << id << " done." << std::endl;
}

int main() {
    int numProducers = 3; // the number of producers
    int numConsumers = 2; // the number of consumers
    int numItemsPerProducer = 5; // the number of items each producer produces

    std::vector<std::thread> producerThreads;
    std::vector<std::thread> consumerThreads;

    // create producers
    for (int i = 0; i < numProducers; ++i) {
        producerThreads.emplace_back(producer, i + 1, numItemsPerProducer);
    }

    // create consumers
    for (int i = 0; i < numConsumers; ++i) {
        consumerThreads.emplace_back(consumer, i + 1);
    }

    // wait for all producers to finish
    for (auto& pt : producerThreads) {
        pt.join();
    }

    {
        std::lock_guard<std::mutex> lock(mtx);
        done = true; // setup done flag
    }

    cv.notify_all(); // notify all consumers

    // wait for all consumers to finish
    for (auto& ct : consumerThreads) {
        ct.join();
    }

    std::cout << "All producers and consumers are done." << std::endl;

    return 0;
}
