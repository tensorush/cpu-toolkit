/*
    Comb Sort (stable)
    -------------------------
    Time: Ω(n) Θ(n^2) O(n^2)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template<typename T>
void CombSort(std::vector<T>& array) {
    bool swapped = false;
    size_t gap = array.size();
    const double shrink = 1.3;
    while (gap > 1 || swapped) {
        if (gap > 1) gap = (size_t)(gap / shrink);
        swapped = false;
        for (size_t i = 0; gap + i < array.size(); ++i) {
            if (array[i] > array[i + gap]) {
                std::swap(array[i], array[i + gap]);
                swapped = true;
            }
        }
    }
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element) {
        array.emplace_back(element);
    }
    CombSort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}