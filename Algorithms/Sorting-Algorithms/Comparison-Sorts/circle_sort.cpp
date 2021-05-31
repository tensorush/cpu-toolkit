/*
    Circle Sort (unstable)
    -------------------------------------------------
    Time: Ω(n log(n)) Θ(n log(n)) O(n log(n) log(n))
    Space: O(1)
*/
#include <iostream>
#include <vector>

template<typename T>
bool CircleSort(std::vector<T>& array, const size_t& low, const size_t& high, bool swapped = false) {
    if (low == high) return swapped;
    size_t i, j, mid = (high - low) / 2;
    for (i = low, j = high; i < j; ++i, --j) {
        if (array[i] > array[j]) {
            std::swap(array[i], array[j]);
            swapped = true;
        }
    }
    if (i == j && array[i] > array[j + 1]) {
        std::swap(array[i], array[j + 1]);
        swapped = true;
    }
    return (swapped || CircleSort(array, low, low + mid) || CircleSort(array, low + mid + 1, high));
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element) {
        array.emplace_back(element);
    }
    while (CircleSort(array, 0, array.size() - 1)) ;
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}