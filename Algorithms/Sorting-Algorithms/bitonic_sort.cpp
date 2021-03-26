/*
    Bitonic Sort (stable)
    ---------------------------------------------------------
    Parallel Time: Ω((log(n))^2) Θ((log(n))^2) O((log(n))^2)
    Space: O(n (log(n))^2)
*/
#include <iostream>
#include <vector>

template<typename T>
void BitonicSort(std::vector<T>& array, const size_t& low, const size_t& n, bool ascend, bool merge) {
    if (n <= 1) return ;
    int k = n / 2;
    if (merge) {
        for (int i = low; i < low + k; ++i) {
            if (array[i] > array[i + k] == ascend) std::swap(array[i], array[i + k]);
        }
        BitonicSort(array, low, k, ascend, true);
        BitonicSort(array, low + k, k, ascend, true);
    } else {
        BitonicSort(array, low, k, true, false);
        BitonicSort(array, low + k, k, false, false);
        BitonicSort(array, low, n, ascend, true);
    }
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> array(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    BitonicSort(array, 0, n, true, false);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}