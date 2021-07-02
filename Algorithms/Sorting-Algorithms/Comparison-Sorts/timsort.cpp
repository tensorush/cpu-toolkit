/*
    Timsort (stable)
    -----------------------------------
    Time: Ω(n) Θ(n log(n)) O(n log(n))
    Space: O(n)
*/
#include <algorithm>
#include <iostream>
#include <vector>

const unsigned GetMinrun(unsigned& n) {
    unsigned r = 0;
    while (n > 63) {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}

template <typename T>
void InsertionSort(std::vector<T>& array, const unsigned& low, const unsigned& high) {
    for (unsigned i = low; i <= high; ++i) {
        for (unsigned j = i; j > low && array[j - 1] > array[j]; --j) {
            std::swap(array[j - 1], array[j]);
        }
    }
}

template <typename T>
void Merge(std::vector<T>& array, const unsigned& low, const unsigned& mid, const unsigned& high) {
    // TODO: Galloping mode
    unsigned len_1 = mid - low + 1, len_2 = high - mid;
    std::vector<unsigned> left(len_1), right(len_2);
    unsigned i = 0, j = 0, k = low;
    while (i < len_1 && j < len_2)
        (left[i] <= right[j]) ? (left[i++] = array[k++]) : (right[j++] = array[k++]);
    while (i < len_1)
        left[i++] = array[k++];
    while (j < len_2)
        right[j++] = array[k++];
    for (unsigned i = 0; i < len_1; ++i) {
        array[low + i] = left[i];
    }
    for (unsigned j = 0; j < len_2; ++j) {
        array[mid + 1 + j] = right[j];
    }
}

template <typename T>
void Timsort(std::vector<T>& array) {
    unsigned n = array.size(), minrun = GetMinrun(n);
    for (unsigned i = 0; i < n; i += minrun) {
        InsertionSort(array, i, std::min((i + 31), (n - 1)));
    }
    for (unsigned size = minrun; size < n; size *= 2) {
        for (unsigned low = 0; low < n; low += 2 * size) {
            Merge(array, low, low + size - 1, std::min((low + 2 * size - 1), (n - 1)));
        }
    }
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    Timsort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}