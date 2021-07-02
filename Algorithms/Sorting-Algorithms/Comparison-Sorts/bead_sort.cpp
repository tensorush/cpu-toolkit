/*
    Bead Sort (unstable)
    --------------------
    Time: O(sum(array))
    Space: O(n^2)
*/
#include <iostream>
#include <vector>

void BeadSort(std::vector<unsigned>& array) {
    int max = 0;
    for (const unsigned& element : array) {
        if (element > max)
            max = element;
    }
    unsigned n = array.size();
    std::vector<bool> beads(max * n);
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned element = 0; element < array[i]; ++element) {
            beads[max * i + element] = true;
        }
    }
    for (unsigned element = 0; element < max; ++element) {
        unsigned sum = 0;
        for (unsigned i = 0; i < n; ++i) {
            sum += beads[max * i + element];
            beads[max * i + element] = false;
        }
        for (unsigned i = n - sum; i < n; ++i) {
            beads[max * i + element] = true;
        }
    }
    for (unsigned i = 0; i < n; ++i) {
        unsigned element = 0;
        while (element < max && beads[max * i + element])
            ++element;
        array[i] = element;
    }
}

int main() {
    unsigned element;
    std::vector<unsigned> array;
    while (std::cin >> element)
        array.emplace_back(element);
    BeadSort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}