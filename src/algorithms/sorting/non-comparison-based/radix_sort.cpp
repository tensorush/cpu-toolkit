/*
    Radix Sort (stable)
    ---------------------------
    Time: Ω(n*k) Θ(n*k) O(n*k)
    Space: O(n+k)
*/
#include <iostream>
#include <vector>

void CountingSort(std::vector<int>& array, const unsigned& n, const int& place) {
    const unsigned max = 10;
    std::vector<int> counter(max);
    for (unsigned i = 0; i < max; ++i)
        counter[i] = 0;
    for (unsigned i = 0; i < n; ++i)
        ++counter[(array[i] / place) % max];
    for (unsigned i = 1; i < max; ++i)
        counter[i] += counter[i - 1];
    std::vector<int> arraySorted(n);
    for (int i = n - 1; i >= 0; --i) {
        arraySorted[counter[(array[i] / place) % max] - 1] = array[i];
        --counter[(array[i] / place) % max];
    }
    for (unsigned i = 0; i < n; ++i) {
        array[i] = arraySorted[i];
    }
}

void RadixSort(std::vector<int>& array) {
    int max = INT32_MIN;
    for (const int& element : array) {
        if (element > max)
            max = element;
    }
    for (unsigned place = 1; max / place > 0; place *= 10) {
        CountingSort(array, array.size(), place);
    }
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    RadixSort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}