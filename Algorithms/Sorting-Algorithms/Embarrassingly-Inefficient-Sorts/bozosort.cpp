/*
    Bozosort (unstable)
    ----------------------
    Time: Ω(n) Θ(n!) O(∞)
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
void Bozosort(std::vector<T>& array) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    unsigned n = array.size();
    while (IsSorted(array) == false) {
        std::swap(array[generator() % n], array[generator() % n]);
    }
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    Bozosort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}