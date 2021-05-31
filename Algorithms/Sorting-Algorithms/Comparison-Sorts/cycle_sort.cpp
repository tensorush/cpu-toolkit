/*
    Cycle Sort (unstable)
    ---------------------------
    Time: Ω(n^2) Θ(n^2) O(n^2)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template<typename T>
void CycleSort(std::vector<T>& array) {
    for (size_t start = 0; start <= array.size() - 2; ++start) {
        size_t pos = start;
        T element = array[start];
        for (size_t i = start + 1; i < array.size(); ++i) {
            if (array[i] < element) ++pos;
        }
        if (pos == start) continue ;
        while (element == array[pos]) ++pos;
        if (pos != start) std::swap(element, array[pos]);
        while (pos != start) {
            pos = start;
            for (size_t i = start + 1; i < array.size(); ++i) {
                if (array[i] < element) ++pos;
            }
            while (element == array[pos]) ++pos;
            if (element != array[pos]) std::swap(element, array[pos]);
        }
    }
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element) {
        array.emplace_back(element);
    }
    CycleSort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}