/*
    Combinations With Repetitions
    -----------------------------
    Time: O((n+k-1)!/k!/(n-1)!)
    Space: O(1)
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

template<typename T>
void _CombinationsWithRepetitions(const std::vector<T>& set, std::vector<T>& combination, std::vector<std::vector<T>>& combinations, unsigned setIndex = 0, const unsigned& combIndex = 0) {
    if (combIndex == combination.size()) {
        combinations.emplace_back(combination);
        return ;
    }
    while (setIndex < set.size()) {
        combination[combIndex] = set[setIndex];
        _CombinationsWithRepetitions(set, combination, combinations, setIndex++, combIndex + 1);
    }
}

template<typename T>
auto CombinationsWithRepetitions(std::vector<T>& set, const unsigned& k) {
    std::vector<T> combination(k);
    std::sort(set.begin(), set.end());
    std::vector<std::vector<T>> combinations;
    _CombinationsWithRepetitions(set, combination, combinations);
    return combinations;
}

int main() {
    unsigned n, k;
    std::cin >> n >> k;
    std::vector<char> set(n);
    for (char& element : set) {
        std::cin >> element;
    }
	auto combinations = CombinationsWithRepetitions(set, k);
    for (const std::vector<char>& combination : combinations) {
        for (const char& element : combination) {
            std::cout << element;
        }
        std::cout << std::endl;
    }

	return EXIT_SUCCESS;
}