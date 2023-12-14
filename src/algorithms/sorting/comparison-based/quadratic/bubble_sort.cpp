/*
    Bubble Sort (stable)
    -------------------------
    Time: Ω(n) Θ(n^2) O(n^2)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template <typename T>
void BubbleSort(std::vector<T>& array) {
    unsigned n = array.size();
    for (unsigned i = 0; i < n - 1; ++i) {
        for (unsigned j = 0; j < n - 1 - i; ++j) {
            if (array[j] > array[j + 1])
                std::swap(array[j], array[j + 1]);
        }
    }
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    BubbleSort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}