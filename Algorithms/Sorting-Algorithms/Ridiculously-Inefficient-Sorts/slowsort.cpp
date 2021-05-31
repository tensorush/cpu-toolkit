/*
    Slowsort (stable)
    ------------------------------------------------------
    Time: Ω(n^(log(n)/2)) Θ(n^(log(n)/2)) O(n^(log(n)/2))
    Space: O(n)
*/
#include <iostream>
#include <vector>

template<typename T>
void Slowsort(std::vector<T>& array, const size_t& low, const size_t& high) {
    if (low >= high) return ;
    size_t mid = low + (high - low) / 2;
    Slowsort(array, low, mid);
    Slowsort(array, mid + 1, high);
    if (array[mid] > array[high]) std::swap(array[mid], array[high]);
    Slowsort(array, low, high - 1);
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element) {
        array.emplace_back(element);
    }
    Slowsort(array, 0, array.size() - 1);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}