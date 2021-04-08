/*
    Slow Sort (stable)
    ------------------------------------------------------
    Time: Ω(n^(log(n)/2)) Θ(n^(log(n)/2)) O(n^(log(n)/2))
    Space: O(n)
*/
#include <iostream>
#include <vector>

template<typename T>
void SlowSort(std::vector<T>& array, const size_t& low, const size_t& high) {
    if (low >= high) return ;
    size_t mid = low + (high - low) / 2;
    SlowSort(array, low, mid);
    SlowSort(array, mid + 1, high);
    if (array[mid] > array[high]) std::swap(array[mid], array[high]);
    SlowSort(array, low, high - 1);
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    SlowSort(array, 0, array.size() - 1);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}