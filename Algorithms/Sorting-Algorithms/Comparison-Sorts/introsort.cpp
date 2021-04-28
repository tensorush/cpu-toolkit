/*
    Introsort (unstable)
    ------------------------------------------
    Time: Ω(n log(n)) Θ(n log(n)) O(n log(n))
    Space: O(log(n))
*/
#include <iostream>
#include <vector>
#include <cmath>

template<typename T>
void InsertionSort(std::vector<T>& array, const size_t& low, const size_t& high) {
    for (size_t i = low; i <= high; ++i) {
        for (size_t j = i; j > low && array[j - 1] > array[j]; --j) {
            std::swap(array[j - 1], array[j]);
        }
    }
}

template<typename T>
void SiftDown(std::vector<T>& heap, const size_t& i, const size_t& n) {
    size_t i_max = i, left = 2 * i + 1, right = left + 1;
    if (left < n && heap[left] > heap[i_max]) i_max = left;
    if (right < n && heap[right] > heap[i_max]) i_max = right;
    if (i_max != i) {
        std::swap(heap[i], heap[i_max]);
        SiftDown(heap, i_max, n);
    }
}

template<typename T>
void Heapify(std::vector<T>& array, const size_t& low, const size_t& high) {
    for (int i = (high + 1) / 2 - 1; i >= low; --i) {
        SiftDown(array, i, high + 1);
    }
}

template<typename T>
void Heapsort(std::vector<T>& array, const size_t& low, const size_t& high) {
    Heapify(array, low, high);
    for (int i = high, n = high + 1; i > low; --i) {
        std::swap(array[low], array[i]);
        SiftDown(array, low, --n);
    }
}

template<typename T>
size_t Quicksort2(std::vector<T>& array, const size_t& low, const size_t& high) {
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
    return j;
}

template<typename T>
void Introsort(std::vector<T>& array, const size_t& low, const size_t& high, const size_t& maxDepth) {
    if (high - low < 16) {
        InsertionSort(array, low, high);
    } else if (maxDepth == 0) {
        Heapsort(array, low, high);
    } else {
        size_t pivotIndex = Quicksort2(array, low, high);
        Introsort(array, low, pivotIndex, maxDepth - 1);
        Introsort(array, pivotIndex + 1, high, maxDepth - 1);
    }
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element) {
        array.emplace_back(element);
    }
    Introsort(array, 0, array.size() - 1, 2 * log(array.size()));
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}