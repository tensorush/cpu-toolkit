/*
    Combinations Without Repetitions
    --------------------------------
    Time: O(n!/k!/(n-k)!)
    Space: O(1)
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

template <typename T>
void _CombinationsWithoutRepetitions(const std::vector<T>& set, std::vector<T>& combination, std::vector<std::vector<T>>& combinations, unsigned setIndex = 0, const unsigned& combIndex = 0) {
    if (combIndex == combination.size()) {
        combinations.emplace_back(combination);
        return;
    }
    if (setIndex >= set.size())
        return;
    combination[combIndex] = set[setIndex];
    _CombinationsWithoutRepetitions(set, combination, combinations, setIndex + 1, combIndex + 1);
    while (set[setIndex] == set[setIndex + 1])
        ++setIndex;
    _CombinationsWithoutRepetitions(set, combination, combinations, setIndex + 1, combIndex);
}

template <typename T>
auto CombinationsWithoutRepetitions(std::vector<T>& set, const unsigned& k) {
    std::vector<T> combination(k);
    std::sort(set.begin(), set.end());
    std::vector<std::vector<T>> combinations;
    _CombinationsWithoutRepetitions(set, combination, combinations);
    return combinations;
}

int main() {
    unsigned n, k;
    std::cin >> n >> k;
    std::vector<char> set(n);
    for (char& element : set) {
        std::cin >> element;
    }
    auto combinations = CombinationsWithoutRepetitions(set, k);
    for (const std::vector<char>& combination : combinations) {
        for (const char& element : combination) {
            std::cout << element;
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}