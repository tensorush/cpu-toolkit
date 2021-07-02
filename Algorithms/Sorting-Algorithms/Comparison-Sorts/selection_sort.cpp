/*
    Selection Sort (stable)
    ---------------------------
    Time: Ω(n^2) Θ(n^2) O(n^2)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template <typename T>
void SelectionSort(std::vector<T>& array) {
    unsigned n = array.size();
    for (unsigned i = 0; i < n; ++i) {
        unsigned minIndex = i;
        for (unsigned j = i + 1; j < n; ++j) {
            if (array[j] < array[minIndex])
                minIndex = j;
        }
        std::swap(array[i], array[minIndex]);
    }
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    SelectionSort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}