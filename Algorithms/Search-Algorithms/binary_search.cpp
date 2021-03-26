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
    int low = -1, high = array.size();
    while (low < high - 1) {
        size_t mid = (low + high) / 2;
        (array[mid] < key)?(low = mid):(high = mid); // left-sided
        // (array[mid] >= key)?(low = mid):(high = mid); // right-sided
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