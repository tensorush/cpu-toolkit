/*
    Interpolation Search
    -------------------------
    Time: Θ(log(log(n))) O(n)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template<typename T>
int InterpolationSearch(const std::vector<T>& array, const T& key) {
    size_t left = 0, right = array.size() - 1;
    while (array[left] < key && key < array[right]) {
        size_t mid = left + (key - array[left]) * (right - left) / (array[right] - array[left]);
        if (array[mid] < key) {
            left = mid + 1;
        } else if (array[mid] > key) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    if (array[left] == key) {
        return left;
    } else if (array[right] == key) {
        return right;
    } else {
        return -1;
    }
}

int main() {
    int key;
    unsigned n;
    std::cin >> n >> key;
    std::vector<int> array(n);
    for (int& element : array) {
        std::cin >> element;
    }
    std::cout << InterpolationSearch(array, key) << std::endl;

    return 0;
}