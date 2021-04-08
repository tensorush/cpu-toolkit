/*
    Odd-Even Sort (stable)
    -------------------------
    Time: Ω(n) Θ(n^2) O(n^2)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template<typename T>
void OddEvenSort(std::vector<T>& array) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (size_t i = 1; i < array.size() - 1; i += 2) {
            if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
                sorted = false;
            }
        }
        for (size_t i = 0; i < array.size() - 1; i += 2) {
            if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
                sorted = false;
            }
        }
    }
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> array(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    OddEvenSort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}