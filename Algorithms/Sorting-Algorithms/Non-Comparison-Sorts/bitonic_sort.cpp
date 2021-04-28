/*
    Bitonic Sort (stable)
    ---------------------------------------------------------
    Parallel Time: Ω((log(n))^2) Θ((log(n))^2) O((log(n))^2)
    Space: O(n (log(n))^2)
*/
#include <iostream>
#include <vector>

template<typename T>
void BitonicSort(std::vector<T>& array, const size_t& low, const size_t& high, const bool& ascend, const bool& merge) {
    if (high <= 1) return ;
    size_t k = high / 2;
    if (merge) {
        for (int i = low; i < low + k; ++i) {
            if (array[i] > array[i + k] == ascend) std::swap(array[i], array[i + k]);
        }
        BitonicSort(array, low, k, ascend, true);
        BitonicSort(array, low + k, k, ascend, true);
    } else {
        BitonicSort(array, low, k, true, false);
        BitonicSort(array, low + k, k, false, false);
        BitonicSort(array, low, high, ascend, true);
    }
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element) {
        array.emplace_back(element);
    }
    BitonicSort(array, 0, array.size(), true, false);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}