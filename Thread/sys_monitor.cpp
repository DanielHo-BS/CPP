#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <mutex>
#include <cstdlib>
#include <iomanip>
#include <atomic>

std::mutex mtx;
std::atomic<bool> running(true);

void clearScreen() {
    std::cout << "\033[2J\033[H"; // ANSI escape codes to clear screen and move cursor to top-left
}

void monitorCPU(std::string &output) {
    std::ifstream statFile("/proc/stat");
    std::string line;
    if (std::getline(statFile, line)) {
        std::istringstream iss(line);
        std::string cpu;
        long user, nice, system, idle;
        iss >> cpu >> user >> nice >> system >> idle;
        std::ostringstream oss;
        oss << "CPU Usage: User=" << user << " Nice=" << nice
            << " System=" << system << " Idle=" << idle;
        output = oss.str();
    }
    statFile.close();
}

void monitorMemory(std::string &output) {
    std::ifstream memFile("/proc/meminfo");
    std::string line;
    long totalMemory = 0, freeMemory = 0;
    while (std::getline(memFile, line)) {
        std::istringstream iss(line);
        std::string key;
        long value;
        std::string unit;
        iss >> key >> value >> unit;
        if (key == "MemTotal:") totalMemory = value;
        if (key == "MemFree:") freeMemory = value;
        if (totalMemory > 0 && freeMemory > 0) break;
    }
    std::ostringstream oss;
    oss << "Memory Usage: Total=" << totalMemory << " KB Free=" << freeMemory << " KB";
    output = oss.str();
    memFile.close();
}

void monitorDisk(std::string &output) {
    std::system("df -h > disk_usage.txt");
    std::ifstream diskFile("disk_usage.txt");
    std::string line;
    std::ostringstream oss;
    while (std::getline(diskFile, line)) {
        oss << line << "\n";
    }
    output = "Disk Usage:\n" + oss.str();
    diskFile.close();
}

void refreshDisplay() {
    std::string cpuOutput, memOutput, diskOutput;
    while (running) {
        monitorCPU(cpuOutput);
        monitorMemory(memOutput);
        monitorDisk(diskOutput);

        {
            std::lock_guard<std::mutex> lock(mtx);
            clearScreen();
            std::cout << "Press Enter to exit...\n";
            std::cout << cpuOutput << "\n"
                      << memOutput << "\n"
                      << diskOutput << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    std::thread displayThread(refreshDisplay);

    // Allow the program to run until a key is pressed
    std::cout << "Press Enter to exit...\n";
    std::cin.get();
    running = false;

    displayThread.join();
    return 0;
}
