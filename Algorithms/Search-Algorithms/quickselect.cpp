/*
    Quickselect
    -----------
    Time: O(n)
    Space: O(1)
*/
#include <algorithm>
#include <iostream>
#include <vector>

template<typename T>
T Quickselect(std::vector<T>& array, const size_t& left, const size_t& right, const size_t& k) {
    if (left == right) return array[left];
    // "Median-of-Medians" pivot selection strategy
    size_t n = right - left + 1;
    std::vector<T> medians, subgroup;
    for (size_t i = 0; i < (n + 4) / 5; ++i) {
        size_t elements = 5;
        if (i * 5 + 5 > n) elements = n % 5;
        for (auto it = array.begin() + left + i * 5; it != array.begin() + left + i * 5 + elements; ++it) {
            subgroup.emplace_back(*it);
        }
        std::sort(subgroup.begin(), subgroup.end());
        medians.emplace_back(subgroup[subgroup.size() / 2]);
    }
    T pivot = Quickselect(medians, 0, medians.size() - 1, medians.size() / 2);
    size_t pivotIndex = std::find(array.begin(), array.end(), pivot) - array.begin();
    std::swap(array[pivotIndex], array[left]);
    // Hoare's partitioning scheme
    size_t pivot = left, i = left, j = right + 1;
    while (i < j) {
        while (++i < j && array[i] < array[pivot]);
        while (--j >= i && array[j] >= array[pivot]);
        if (i <= j) std::swap(array[i], array[j]);
    }
    std::swap(array[pivot], array[j]);
    if (k - 1 == j) return array[j];
    return (k - 1 < j)?(Quickselect(array, left, j - 1, k)):(Quickselect(array, j + 1, right, k));
}

int main() {
    size_t n, k;
    std::cin >> n >> k;
    std::vector<int> array(n);
    for (int& element : array) {
        std::cin >> element;
    }
    std::cout << Quickselect(array, 0, n - 1, k) << std::endl;

    return 0;
}