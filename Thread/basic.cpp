// Description: Basic tests for the thread class.
// Create two threads for counting up and down.

#include <iostream>
#include <thread>

void countUp() {
  for (int i = 0; i < 10; i++) {
    std::cout << "Counting up: " << i << std::endl;
  }
}

void countDown() {
  for (int i = 10; i > 0; i--) {
    std::cout << "Counting down: " << i << std::endl;
  }
}

int main() {
  std::thread t1(countUp);
  std::thread t2(countDown);

  t1.join();
  t2.join();

  std::cout << "Finished counting." << std::endl;

  return 0;
}