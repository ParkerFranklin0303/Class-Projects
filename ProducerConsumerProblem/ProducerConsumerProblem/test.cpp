#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

const int BUFFER_SIZE = 2; // Golbal variable that defines buffer size.

std::mutex mutexLock; // A Mutex Lock
std::condition_variable conditionalVariable; // A Conditional Variable
std::vector<int> buffer; // A Vector of 'int' to act as the buffer

// Producer Implenetation
void producer(int id) {
    for (int i = 0; i < 3; ++i) { // For 'i < int' total items where the producer will produce an item before terminating:
        std::unique_lock<std::mutex> lock(mutexLock);
        conditionalVariable.wait(lock, [] { return buffer.size() < BUFFER_SIZE; });

        int item = id + i; //*10 + i; // Defines what value an item is.
        buffer.push_back(item); // Puts an item into the buffer.
        std::cout << "Producer " << id << " produced: " << item << std::endl;

        conditionalVariable.notify_one();
    }
}

// Consumer Implementation
void consumer(int id) {
    for (int i = 0; i < 3; ++i) { // For 'i < int' total items where the consumer will consume an item before terminating:
        std::unique_lock<std::mutex> lock(mutexLock);
        conditionalVariable.wait(lock, [] { return !buffer.empty(); });

        int item = buffer.front(); // Sets item to equal the item at the front of the queue (= The oldest item in the queue!)
        buffer.erase(buffer.begin()); // Erases the item at the front of the buffer.
        std::cout << "Consumer " << id << " consumed: " << item << std::endl;

        conditionalVariable.notify_one();
    }
}

int main() {
    std::thread p1(producer, 1);
    //std::thread p2(producer, 2);
    std::thread c1(consumer, 1);
    //std::thread c2(consumer, 2);

    p1.join(); // Blocks thread 'p1' until the function called in its initialization parameter finishes executing.
    //p2.join();
    c1.join(); // Blocks thread 'c1' until the function called in its initialization parameter finishes executing.
    //c2.join();

    return 0;
}