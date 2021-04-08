/*
    Quicksort with 3-Way Dual-Pivot Partitioning (unstable)
    -------------------------------------------------------
    Time: Ω(n) Θ(n log(n)) O(n^2)
    Space: O(log(n))
*/
#include <iostream>
#include <vector>

template<typename T>
void Quicksort3(std::vector<T>& array, int low, int high) {
    if (low >= high) return ;
    // TODO: mid1, mid2 pivots
    if (array[low] > array[high]) std::swap(array[low], array[high]);
    T pivot_1 = array[low], pivot_2 = array[high];
    int i, less = low + 1, greater = high - 1;
    for (i = low + 1; i <= greater; ++i) {
        if (array[i] < pivot_1) {
            std::swap(array[i], array[less++]);
        } else if (array[i] >= pivot_2) {
            while (array[greater] > pivot_2 && i < greater) --greater;
            std::swap(array[i], array[greater--]);
            if (array[i] < pivot_1) std::swap(array[i], array[less++]);
        }
    }
    --less; ++greater;
    std::swap(array[low], array[less]);
    std::swap(array[high], array[i]);
    Quicksort3(array, low, less - 1);
    Quicksort3(array, less + 1, i - 1);
    Quicksort3(array, i + 1, high);
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> array(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    Quicksort3(array, 0, n - 1);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}