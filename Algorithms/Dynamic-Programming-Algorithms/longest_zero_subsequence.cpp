/*
    Longest Zero Subsequence
    ------------------------
    Time: O(n*sequenceSum)
    Space: O(sequenceSum)
*/
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>

unsigned LongestZeroSubsequence(const std::vector<int>& sequence) {
    std::unordered_map<int, unsigned> maxLengths, temp;
    maxLengths.emplace(0, 0);
    temp = maxLengths;
    for (const int& element : sequence) {
        for (const auto& [subsum, maxLength] : maxLengths) {
            unsigned defaultOption = 0;
            auto it = maxLengths.find(subsum + element);
            if (it != maxLengths.end()) defaultOption = it->second;
            temp[subsum + element] = std::max(defaultOption, maxLengths[subsum] + 1);
        }
        maxLengths = temp;
    }
    return maxLengths[0];
}

int main() {
    unsigned numElements;
    std::cin >> numElements;
    std::vector<int> sequence(numElements);
    for (int& element : sequence) {
        std::cin >> element;
    }
    std::cout << LongestZeroSubsequence(sequence) << std::endl;

    return EXIT_SUCCESS;
}