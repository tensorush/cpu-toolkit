/*
    Quicksort with 2-Way Partitioning (unstable)
    --------------------------------------------
    Time: Ω(n log(n)) Θ(n log(n)) O(n^2)
    Space: O(log(n))
*/
#include <iostream>
#include <vector>

template<typename T>
void Quicksort2(std::vector<T>& array, int low, int high) {
    if (low >= high) return ;
    // "Median-of-Three" pivot selection strategy
    int mid = low + (high - low) / 2;
    if (array[high] < array[low]) std::swap(array[high], array[low]);
    if (array[mid] < array[low]) std::swap(array[mid], array[low]);
    if (array[high] < array[mid]) std::swap(array[high], array[mid]);
    const T pivot = array[mid];
    // Hoare's partitioning scheme
    int i = low, j = high;
    while (i <= j) {
        while (array[i] < pivot) ++i;
        while (array[j] > pivot) --j;
        if (i <= j) std::swap(array[i++], array[j--]);
    }
    if (low < j) Quicksort2(array, low, j);
    if (high > i) Quicksort2(array, i, high);
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> array(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    Quicksort2(array, 0, n - 1);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}