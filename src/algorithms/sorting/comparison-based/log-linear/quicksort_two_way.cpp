/*
    Quicksort with Two-Way Partitioning (unstable)
    ----------------------------------------------
    Time: Ω(n log(n)) Θ(n log(n)) O(n^2)
    Space: O(log(n))
*/
#include <iostream>
#include <vector>

template <typename T>
void QuicksortTwoWay(std::vector<T>& array, const unsigned& low, const unsigned& high) {
    if (low >= high)
        return;
    // "Median-of-Three" pivot selection strategy
    unsigned mid = low + (high - low) / 2;
    if (array[high] < array[low])
        std::swap(array[high], array[low]);
    if (array[mid] < array[low])
        std::swap(array[mid], array[low]);
    if (array[high] < array[mid])
        std::swap(array[high], array[mid]);
    T pivot = array[mid];
    // Hoare's partitioning scheme
    unsigned i = low, j = high;
    while (true) {
        while (array[i] < pivot)
            ++i;
        while (array[j] > pivot)
            --j;
        if (i >= j)
            break;
        std::swap(array[i++], array[j--]);
    }
    QuicksortTwoWay(array, low, j);
    QuicksortTwoWay(array, j + 1, high);
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    QuicksortTwoWay(array, 0, array.size() - 1);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}