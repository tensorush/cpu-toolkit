/*
    Insertion Sort (stable)
    -------------------------
    Time: Ω(n) Θ(n^2) O(n^2)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template <typename T>
void InsertionSort(std::vector<T>& array) {
    unsigned n = array.size();
    for (unsigned i = 1; i < n; ++i) {
        for (unsigned j = i; j > 0 && array[j - 1] > array[j]; --j) {
            std::swap(array[j - 1], array[j]);
        }
    }
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    InsertionSort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}