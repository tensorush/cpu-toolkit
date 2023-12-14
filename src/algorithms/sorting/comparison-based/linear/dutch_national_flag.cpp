/*
    Dutch National Flag (stable)
    ----------------------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template <typename T>
void DutchNationalFlag(std::vector<T>& array, size_t& mid) {
    int low = 0, equal = 0, high = array.size() - 1;
    while (equal <= high) {
        if (array[equal] < mid)
            std::swap(array[low++], array[equal++]);
        else if (array[equal] > mid)
            std::swap(array[equal], array[high--]);
        else
            ++equal;
    }
}

int main() {
    size_t mid;
    std::cin >> mid;
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    DutchNationalFlag(array, mid);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}