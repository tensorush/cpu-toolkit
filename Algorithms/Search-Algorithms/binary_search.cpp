/*
    Binary Search
    ---------------
    Time: O(log(n))
    Space: O(1)
*/
#include <iostream>
#include <vector>

template<typename T>
size_t BinarySearch(const std::vector<T>& array, const T& key) {
    size_t low = 0, high = array.size() - 1;
    while (low < high) {
        size_t mid = low + (high - low) / 2;
        (array[mid] < key)?(low = mid + 1):(high = mid);
    }
    return high;
}

int main() {
    int key;
    size_t n;
    std::cin >> n >> key;
    std::vector<int> array(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    std::cout << BinarySearch(array, key) << std::endl;

    return 0;
}