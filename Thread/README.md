# Thread

Excercise `Thread`
- basic thread
- basic thread with mutex
- basic thread with condition variable: producer-consumer problem
- System Resource Monitor

## Excercise

### Basic Thread

Create two threads that count from 1 to 10. The first thread should count from 1 to 10 and the second thread should count from 10 to 1. The threads should print the numbers they are counting and the thread number. The output should look like this:

```cpp
// Example of basic thread

def func(){
    //TODO
}

int main() {
    std::thread thread1(func);
    std::thread thread2(func);
    thread1.join();
    thread2.join();
    return 0;
}
```
### Basic Thread with Mutex

Depending on the `Basic Thread` exercise, add a mutex to stop the shared resource from being accessed by both threads at the same time. The output should look like this:

```cpp
// Example of mutex

std::mutex mtx;
int shared_data = 0;

def func(){
    //TODO with mutex to protect shared_data
    std::lock_guard<std::mutex> lock(mtx); // lock the mutex automatically
    shared_data++;
}

int main() {
    std::thread thread1(func);
    std::thread thread2(func);
    thread1.join();
    thread2.join();
    return 0;
}
```


### Basic Thread with Condition Variable

The tread should be able when some condition is met. The output should look like this:

```cpp
// Example of condition variable

std::mutex mtx;
std::condition_variable cv;
int shared_data = 0;

def func(){
    //TODO with condition variable
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{return shared_data == 0;});  // wait for condition
    shared_data++;
    cv.notify_all();  // notify all threads that are waiting
}

int main() {
    std::thread thread1(func);
    std::thread thread2(func);
    thread1.join();
    thread2.join();
    return 0;
}
```

#### `lock_guard` and `unique_lock`

`lock_guard` is a class template that provides a convenient way to acquire and release lock. It is used with `mutex` to lock and unlock automatically. It is used to lock the mutex until the end of the scope. It is used when we want to lock the mutex until the end of the scope.

- Only provides lock and unlock
- Cannot unlock manually
- Using on simple cases

`unique_lock` is a class template that provides a more flexible way to lock and unlock mutex. It is used with `mutex` to lock and unlock manually. It is used when we want to lock the mutex for a certain period of time.

- Provides lock, unlock, try_lock
- Can unlock manually
- defer_lock, try_to_lock, adopt_lock
- try_lock_until, try_lock_for with std::timed_mutex
- support transfer of lock ownership: std::move

#### Condition Variable

`condition_variable` is a synchronization primitive that can be used to block a thread or multiple threads at the same time until another thread both modifies a shared variable (the condition), and notifies the `condition_variable`.

- `wait()`: The thread will be blocked until the condition is met.
- `wait(lock, pred)`: The thread will be blocked until the condition is met or the predicate returns false.
- `notify_one()`: Notify one thread that is waiting.
- `notify_all()`: Notify all threads that are waiting.

#### Common Mistakes

- Always use `unique_lock` with `condition_variable`.
- Always use `condition_variable` with `mutex`.
- Avoid `deadlock` by using `unique_lock` with `condition_variable`.
- Aviod `spurious wake` by using `condition_variable` with `predicate`.
- Valid notify
  - `notify_one()`: Notify one thread that is waiting.
  - `notify_all()`: Notify all threads that are waiting. Need to pay attention to performance issue to avoid `thundering herd`.


### System Resource Monitor

Implement a system resource monitor that monitors the CPU, memory, and disk usage of the system. The monitor should be able to display the usage of each resource in real-time. The monitor should also be able to display the average usage of each resource over a period of time.

## Run the code

```bash
# Complier with CMake and Make
./rebuild.sh

# run all in ./build/<File Name>
./build/*
```