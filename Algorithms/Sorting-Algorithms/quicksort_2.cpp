/*
    Quicksort with 2-Way Partitioning (unstable)
    --------------------------------------------
    Time: Ω(n log(n)) Θ(n log(n)) O(n^2)
    Space: O(log(n))
*/
#include <iostream>
#include <vector>

template<typename T>
void Quicksort2(std::vector<T>& array, size_t low, size_t high) {
    if (low >= high) return ;
    // "Median-of-Three" pivot selection strategy
    size_t mid = low + (high - low) / 2;
    if (array[high] < array[low]) std::swap(array[high], array[low]);
    if (array[mid] < array[low]) std::swap(array[mid], array[low]);
    if (array[high] < array[mid]) std::swap(array[high], array[mid]);
    T pivot = array[mid];
    // Hoare's partitioning scheme
    size_t i = low, j = high;
    while (true) {
        while (array[i] < pivot) ++i;
        while (array[j] > pivot) --j;
        if (i >= j) break;
        std::swap(array[i++], array[j--]);
    }
    // Tail call elimination
    if (j - low + 1 < high - j) {
        Quicksort2(array, low, j);
        low = j + 1;
    } else {
        Quicksort2(array, j + 1, high);
        high = j;
    }
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