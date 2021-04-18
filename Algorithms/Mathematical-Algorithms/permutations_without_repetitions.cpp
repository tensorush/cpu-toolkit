/*
    Permutations Without Repetitions
    --------------------------------
    Time: O(n!)
    Space: O(1)
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

template<typename T>
auto PermutationsWithoutRepetitions(std::vector<T>& sequence) {
    std::vector<std::vector<T>> permutations;
    std::sort(sequence.begin(), sequence.end());
    bool done = false;
    while (!done) {
        permutations.emplace_back(sequence);
        int first = sequence.size() - 2;
        while (first >= 0) {
            if (sequence[first] < sequence[first + 1]) break;
            --first;
        }
        if (first == -1) done = true;
        int toSwap = sequence.size() - 1;
        while (sequence[first] >= sequence[toSwap]) --toSwap;
        std::swap(sequence[first++], sequence[toSwap]);
        toSwap = sequence.size() - 1;
        while (first < toSwap) std::swap(sequence[first++], sequence[toSwap--]);
    }
    return permutations;
}

int main() {
    size_t n;
    std::cin >> n;
	std::vector<char> sequence(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> sequence[i];
    }
	auto permutations = PermutationsWithoutRepetitions(sequence);
    for (const auto& permutation : permutations) {
        for (const auto& element : permutation) {
            std::cout << element;
        }
        std::cout << std::endl;
    }

	return 0;
}