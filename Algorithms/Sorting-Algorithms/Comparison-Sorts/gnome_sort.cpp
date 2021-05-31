/*
    Gnome Sort (stable)
    -------------------------
    Time: Ω(n) Θ(n^2) O(n^2)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template<typename T>
void GnomeSort(std::vector<T>& array) {
    for (size_t i = 1; i < array.size(); ) {
        if (array[i - 1] > array[i]) {
            std::swap(array[i - 1], array[i]);
            if (i > 1) --i;
        } else {
            ++i;
        }
    }
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element) {
        array.emplace_back(element);
    }
    GnomeSort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}