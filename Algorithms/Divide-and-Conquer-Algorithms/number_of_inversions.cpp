/*
    Number Of Inversions
    --------------------
    Time: O(n log(n))
    Space: O(n)
*/
#include <iostream>
#include <vector>

template<typename T>
size_t CountInversions(std::vector<T>& array, std::vector<T>& temp, size_t low, size_t mid, size_t high) {
    size_t inversionsCount = 0, i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (array[i] <= array[j]) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
            inversionsCount += mid - i + 1;
        }
    }
    while (i <= mid) temp[k++] = array[i++];
    for (size_t i = low; i <= high; ++i) {
        array[i] = temp[i];
    }
    return inversionsCount;
}

template<typename T>
size_t NumberOfInversions(std::vector<T>& array, size_t left, size_t right) {
    if (right == left) return 0;
    std::vector<T> temp = array;
    size_t numInversions = 0, mid = left + (right - left) / 2;
    numInversions += NumberOfInversions(array, left, mid);
    numInversions += NumberOfInversions(array, mid + 1, right);
    numInversions += CountInversions(array, temp, left, mid, right);
    return numInversions;
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> array(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    std::cout << NumberOfInversions(array, 0, array.size() - 1) << std::endl;

    return 0;
}