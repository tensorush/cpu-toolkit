/*
    Pancake Sort (stable)
    ---------------------------
    Time: Ω(n^2) Θ(n^2) O(n^2)
    Space: O(1)
*/
#include <algorithm>
#include <iostream>
#include <vector>

template<typename T>
void PancakeSort(std::vector<T>& array) {
    for (auto cur = array.end(); cur != array.begin() + 1; --cur) {
        auto max = std::max_element(array.begin(), cur);
        if (max != cur - 1) {
            std::reverse(array.begin(), max + 1);
            std::reverse(array.begin(), cur);
        }
    }
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element) {
        array.emplace_back(element);
    }
    PancakeSort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}