/*
    Radix Sort (stable)
    ---------------------------
    Time: Ω(n*k) Θ(n*k) O(n*k)
    Space: O(n+k)
*/
#include <algorithm>
#include <iostream>
#include <vector>

void CountingSort(std::vector<int>& array, size_t n, size_t place) {
    const size_t max = 10;
    std::vector<int> counter(max);
    for (size_t i = 0; i < max; ++i)
        counter[i] = 0;
    for (size_t i = 0; i < n; ++i)
        ++counter[(array[i] / place) % 10];
    for (size_t i = 1; i < max; ++i)
        counter[i] += counter[i - 1];
    std::vector<int> arraySorted(n);
    for (int i = n - 1; i >= 0; --i) {
        arraySorted[counter[(array[i] / place) % 10] - 1] = array[i];
        --counter[(array[i] / place) % 10];
    }
    for (size_t i = 0; i < n; ++i) {
        array[i] = arraySorted[i];
    }
}

void RadixSort(std::vector<int>& array) {
    const int max = *max_element(array.begin(), array.end());
    for (size_t place = 1; max / place > 0; place *= 10) {
        CountingSort(array, array.size(), place);
    }
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> array(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    RadixSort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}