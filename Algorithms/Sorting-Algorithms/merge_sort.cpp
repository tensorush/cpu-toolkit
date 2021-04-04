/*
    Merge Sort (stable)
    ------------------------------------------
    Time: Ω(n log(n)) Θ(n log(n)) O(n log(n))
    Space: O(n)
*/
#include <iostream>
#include <vector>

template<typename T>
void MergeSort(std::vector<T>& array, const size_t& low, const size_t& high) {
    if (low == high) return ;
    size_t mid = low + (high - low) / 2;
    MergeSort(array, low, mid);
    MergeSort(array, mid + 1, high);
    std::vector<T> mergedArray;
    for (size_t i = low, j = mid + 1; i <= mid || j <= high; ) {
        if (i > mid) {
            mergedArray.push_back(array[j++]);
        } else if (j > high) {
            mergedArray.push_back(array[i++]);
        } else if (array[i] <= array[j]) {
            mergedArray.push_back(array[i++]);
        } else {
            mergedArray.push_back(array[j++]);
        }
    }
    for (size_t i = 0; i < mergedArray.size(); ++i) {
        array[low + i] = mergedArray[i];
    }
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> array(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    MergeSort(array, 0, n - 1);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}