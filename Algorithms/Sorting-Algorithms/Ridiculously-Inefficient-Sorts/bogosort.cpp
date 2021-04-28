/*
    Bogosort (unstable)
    --------------------------
    Time: Ω(n) Θ((n+1)!) O(∞)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template<typename T>
bool isSorted(const std::vector<T>& array) {
    for (size_t n = array.size() - 1; n > 0; --n) {
        if (array[n] < array[n - 1]) return false;
    }
    return true;
}

template<typename T>
void Bogosort(std::vector<T>& array) {
    while (!isSorted(array)) {
        for (size_t i = 0, n = array.size(); i < n; ++i) {
            std::swap(array[i], array[rand() % n]);
        }
    }
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element) {
        array.emplace_back(element);
    }
    Bogosort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}