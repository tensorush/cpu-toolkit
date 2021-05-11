/*
    Counting Sort (stable)
    ---------------------------
    Time: Ω(n+k) Θ(n+k) O(n+k)
    Space: O(n+k)
*/
#include <iostream>
#include <vector>

void CountingSort(std::vector<unsigned>& array, const unsigned& maxValue) {
    std::vector<unsigned> counter(maxValue);
    for (size_t i = 0; i < array.size(); ++i) {
        ++counter[array[i]];
    }
    std::vector<size_t> positions(counter.size());
    positions[0] = 0;
    for (size_t j = 1; j < counter.size(); ++j) {
        positions[j] = positions[j - 1] + counter[j - 1];
    }
    std::vector<unsigned> arraySorted(array.size());
    for (size_t i = 0; i < array.size(); ++i) {
        arraySorted[positions[array[i]]] = array[i];
        ++positions[array[i]];
    }
    array = arraySorted;
}

int main() {
    unsigned maxValue, element;
    std::cin >> maxValue;
    std::vector<unsigned> array;
    while (std::cin >> element) {
        array.emplace_back(element);
    }
    CountingSort(array, maxValue);
    for (const unsigned& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}