/*
    Quicksort with Three-Way Single-Pivot Partitioning (unstable)
    -----------------------------------------------------------
    Time: Ω(n) Θ(n log(n)) O(n^2)
    Space: O(log(n))
*/
#include <iostream>
#include <vector>

template <typename T>
void QuicksortWithThreeWaySinglePivot(std::vector<T>& array, const int& low, const int& high) {
    if (low >= high)
        return;
    // "Median-of-Three" pivot selection strategy
    int mid = low + (high - low) / 2;
    if (array[high] < array[low])
        std::swap(array[high], array[low]);
    if (array[mid] < array[low])
        std::swap(array[mid], array[low]);
    if (array[high] < array[mid])
        std::swap(array[high], array[mid]);
    T pivot = array[low];
    // Sedgewick's partitioning scheme
    int i = low + 1, less = low, greater = high;
    while (i <= greater) {
        if (array[i] < pivot)
            std::swap(array[i++], array[less++]);
        else if (array[i] > pivot)
            std::swap(array[i], array[greater--]);
        else
            ++i;
    }
    QuicksortWithThreeWaySinglePivot(array, low, less - 1);
    QuicksortWithThreeWaySinglePivot(array, greater + 1, high);
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    QuicksortWithThreeWaySinglePivot(array, 0, array.size() - 1);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}