/*
    Longest Increasing Subsequence
    ------------------------------
    Time: O(n^2)
    Space: O(n)
*/
#include <algorithm>
#include <iostream>
#include <vector>

template<typename T>
auto LongestIncreasingSubsequence(const std::vector<T>& array) {
    std::vector<T> lis(array.size(), 1), prev(array.size(), -1);
    for (size_t i = 1; i < array.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (array[j] < array[i] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prev[i] = j;
            }
        }
    }
    size_t last = 0;
    for (size_t i = 0; i < array.size(); ++i) {
        if (lis[i] > lis[last]) last = i;
    }
    std::vector<T> solution;
    for (int cur = last; cur >= 0; cur = prev[cur]) {
        solution.emplace_back(cur);
    }
    std::reverse(solution.begin(), solution.end());
    return solution;
}

int main() {
    unsigned n;
    std::cin >> n;
    std::vector<unsigned> array(n);
    for (unsigned& element : array) {
        std::cin >> element;
    }
    auto solution = LongestIncreasingSubsequence(array);
    for (const unsigned& index : solution) {
        std::cout << index << ' ';
    }
    std::cout << std::endl;

    return 0;
}