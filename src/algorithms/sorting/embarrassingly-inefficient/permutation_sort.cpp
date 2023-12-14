/*
    Permutation Sort (stable)
    -------------------------
    Time: Ω(n) Θ(n!) O(n!)
    Space: O(1)
*/
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void PermutationSort(std::vector<T>& array) {
    while (std::next_permutation(array.begin(), array.end()))
        ;
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    PermutationSort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}