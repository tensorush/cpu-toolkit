/*
    Sleep Sort (stable)
    ----------------------------
    Time: O(n log(n) + max(arg))
    Space: O(1)
*/
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    std::vector<std::thread> threads;
    for (int i = 1; i < argc; ++i) {
        threads.emplace_back([i, &argv]() {
            int arg = std::stoi(argv[i]);
            std::this_thread::sleep_for(std::chrono::seconds(arg));
            std::cout << argv[i] << std::endl;
        });
    }
    for (std::thread& thread : threads) {
        thread.join();
    }
}