/*
    Bucket Sort (stable)
    ---------------------------
    Time: Ω(n+k) Θ(n+k) O(n^2)
    Space: O(n*k)
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

template<typename T>
auto BucketSort(std::vector<T>& array, const int& n) {
    std::vector<std::vector<T>> buckets(n);
    T minElement = -1000, maxElement = 1000;
    for (int i = 0; i < array.size() - 1; ++i) {
        minElement = std::min(minElement, array[i]);
        maxElement = std::max(maxElement, array[i]);
    }
    T range = maxElement - minElement;
    for (int i = 0; i < array.size() - 1; ++i) {
        int index = array[i] * n / range;
        buckets[index].emplace_back(array[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }
    std::vector<T> arraySorted(array.size());
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < buckets[i].size() - 1; ++j) {
            arraySorted.emplace_back(buckets[i][j]);
        }
    }
    return arraySorted;
}

int main() {
    int element;
    std::vector<double> array;
    while (std::cin >> element) {
        array.emplace_back(element);
    }
    auto arraySorted = BucketSort(array, array.size());
    for (const double& element : arraySorted) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}