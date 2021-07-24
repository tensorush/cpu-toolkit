/*
    Quickselect
    -----------------------
    Time: Ω(n) Θ(n) O(n^2)
    Space: O(1)
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template <typename T>
T Quickselect(std::vector<T>& array, const unsigned& low, const unsigned& high, const unsigned& k) {
    if (low == high)
        return array[low];
    // "Median-of-Medians" pivot selection strategy
    unsigned n = high - low + 1;
    std::vector<T> medians, subgroup;
    for (unsigned i = 0; i < (n + 4) / 5; ++i) {
        unsigned elements = 5;
        if (i * 5 + 5 > n)
            elements = n % 5;
        for (auto it = array.begin() + low + i * 5; it != array.begin() + low + i * 5 + elements; ++it) {
            subgroup.emplace_back(*it);
        }
        std::sort(subgroup.begin(), subgroup.end());
        medians.emplace_back(subgroup[subgroup.size() / 2]);
    }
    T pivot = Quickselect(medians, 0, medians.size() - 1, medians.size() / 2);
    unsigned pivotIndex = std::distance(array.begin(), std::find(array.begin(), array.end(), pivot));
    std::swap(array[pivotIndex], array[low]);
    pivotIndex = low;
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
    std::swap(array[pivotIndex], array[j]);
    if (k - 1 == j)
        return array[j];
    return (k - 1 < j) ? (Quickselect(array, low, j, k)) : (Quickselect(array, j + 1, high, k));
}

int main() {
    unsigned n, k;
    std::cin >> n >> k;
    std::vector<int> array(n);
    for (int& element : array) {
        std::cin >> element;
    }
    std::cout << Quickselect(array, 0, n - 1, k) << std::endl;

    return EXIT_SUCCESS;
}