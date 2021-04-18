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
void _CombinationsWithRepetitions(const std::vector<T>& set, std::vector<T>& combination, std::vector<std::vector<T>>& combinations, size_t setIndex = 0, const size_t& combIndex = 0) {
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
auto CombinationsWithRepetitions(std::vector<T>& set, const size_t& k) {
    std::vector<T> combination(k);
    std::sort(set.begin(), set.end());
    std::vector<std::vector<T>> combinations;
    _CombinationsWithRepetitions(set, combination, combinations);
    return combinations;
}

int main() {
    size_t n, k;
    std::cin >> n >> k;
    std::vector<char> set(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> set[i];
    }
	auto combinations = CombinationsWithRepetitions(set, k);
    for (const auto& combination : combinations) {
        for (const auto& element : combination) {
            std::cout << element;
        }
        std::cout << std::endl;
    }

	return 0;
}