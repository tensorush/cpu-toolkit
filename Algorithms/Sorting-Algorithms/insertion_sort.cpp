/*
    Insertion Sort (stable)
    -------------------------
    Time: Ω(n) Θ(n^2) O(n^2)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template<typename T>
void InsertionSort(std::vector<T>& array) {
    for (size_t i = 0; i < array.size(); ++i) {
        for (size_t cur = i; cur > 0 && array[cur - 1] > array[cur]; --cur) {
            std::swap(array[cur - 1], array[cur]);
        }
    }
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> array(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    InsertionSort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}