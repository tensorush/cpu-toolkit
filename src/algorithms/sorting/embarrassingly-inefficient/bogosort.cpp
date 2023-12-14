/*
    Bogosort (unstable)
    --------------------------
    Time: Ω(n) Θ((n+1)!) O(∞)
    Space: O(1)
*/
#include <iostream>
#include <random>
#include <chrono>
#include <vector>

template <typename T>
bool IsSorted(const std::vector<T>& array) {
    bool isSorted = true;
    unsigned n = array.size();
    T cur, prev = array.front();
    for (unsigned i = 1; i < n; ++i) {
        cur = array[i];
        if (array[i] < prev) {
            isSorted = false;
            break;
        }
        prev = cur;
    }
    return isSorted;
}

template <typename T>
void Bogosort(std::vector<T>& array) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    while (IsSorted(array) == false) {
        for (unsigned i = 0, n = array.size(); i < n; ++i) {
            std::swap(array[i], array[generator() % n]);
        }
    }
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    Bogosort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}