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
        solution.push_back(cur);
    }
    std::reverse(solution.begin(), solution.end());
    return solution;
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<size_t> array(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    auto solution = LongestIncreasingSubsequence(array);
    for (auto index : solution) {
        std::cout << index << ' ';
    }

    return 0;
}