/*
    Quicksort with Three-Way Dual-Pivot Partitioning (unstable)
    -----------------------------------------------------------
    Time: Ω(n) Θ(n log(n)) O(n^2)
    Space: O(log(n))
*/
#include <iostream>
#include <vector>

constexpr int MIN_EQUAL_ELEMENTS_RANGE = 13;
constexpr int MAX_ARRAY_SIZE_FOR_INSERTION_SORT = 27;

template <typename T>
void QuicksortWithThreeWayDualPivot(std::vector<T>& array, const int& low, const int& high, int divisor) {
    int length = high - low;
    // Insertion sort
    if (length < MAX_ARRAY_SIZE_FOR_INSERTION_SORT) {
        for (int i = low + 1; i <= high; ++i) {
            for (int j = i; j > low && array[j - 1] > array[j]; --j) {
                std::swap(array[j - 1], array[j]);
            }
        }
        return;
    }
    // "Medians-of-Four" pivot selection strategy
    int third = length / divisor, mid_1 = low + third, mid_2 = high - third;
    if (mid_1 <= low)
        mid_1 = low + 1;
    if (mid_2 >= high)
        mid_2 = high - 1;
    if (array[mid_1] < array[mid_2]) {
        std::swap(array[mid_1], array[low]);
        std::swap(array[mid_2], array[high]);
    } else {
        std::swap(array[mid_1], array[high]);
        std::swap(array[mid_2], array[low]);
    }
    T pivot_1 = array[low], pivot_2 = array[high];
    // Yaroslavskiy's partitioning scheme
    int less = low + 1, greater = high - 1;
    for (int i = less; i <= greater; ++i) {
        if (array[i] < pivot_1) {
            std::swap(array[i], array[less++]);
        } else if (array[i] > pivot_2) {
            while (i < greater && array[greater] > pivot_2)
                --greater;
            std::swap(array[i], array[greater--]);
            if (array[i] < pivot_1)
                std::swap(array[i], array[less++]);
        }
    }
    int equalElementsRange = greater - less;
    if (equalElementsRange < MIN_EQUAL_ELEMENTS_RANGE)
        ++divisor;
    std::swap(array[less - 1], array[low]);
    std::swap(array[greater + 1], array[high]);
    QuicksortWithThreeWayDualPivot(array, low, less - 2, divisor);
    QuicksortWithThreeWayDualPivot(array, greater + 2, high, divisor);
    if (equalElementsRange > length - MIN_EQUAL_ELEMENTS_RANGE && pivot_1 != pivot_2) {
        for (int i = less; i <= greater; ++i) {
            if (array[i] == pivot_1) {
                std::swap(array[i], array[less++]);
            } else if (array[i] == pivot_2) {
                std::swap(array[i], array[greater--]);
                if (array[i] == pivot_1)
                    std::swap(array[i], array[less++]);
            }
        }
    }
    if (pivot_1 < pivot_2)
        QuicksortWithThreeWayDualPivot(array, less, greater, divisor);
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    QuicksortWithThreeWayDualPivot(array, 0, array.size() - 1, 3);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}