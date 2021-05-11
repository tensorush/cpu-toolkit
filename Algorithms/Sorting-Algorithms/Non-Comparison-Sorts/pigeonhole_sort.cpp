/*
    Pigeonhole Sort (stable)
    ---------------------------
    Time: Ω(n+k) Θ(n+k) O(n+k)
    Space: O(n+k)
*/
#include <iostream>
#include <vector>

void PigeonholeSort(std::vector<unsigned>& array) {
    unsigned min = UINT32_MAX, max = 0;
    for (const unsigned& element : array) {
        if (element < min) min = element;
        if (element > max) max = element;
    }
    unsigned range = max - min + 1;
    std::vector<std::vector<unsigned>> holes(range);
    for (const unsigned& element : array) {
        holes[element - min].emplace_back(element);
    }
    for (unsigned key = 0, index = 0; key < range; ++key) {
        for (const unsigned& element : holes[key]) {
            array[index] = element;
            ++index;
        }
    }
}

int main() {
    unsigned element;
    std::vector<unsigned> array;
    while (std::cin >> element) {
        array.emplace_back(element);
    }
    PigeonholeSort(array);
    for (const unsigned& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}