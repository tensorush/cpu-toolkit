/*
    Longest Increasing Subsequence
    ------------------------------
    Time: O(n^2)
    Space: O(n)
*/
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
auto LongestIncreasingSubsequence(const std::vector<T>& array) {
    unsigned n = array.size();
    std::vector<T> lis(n, 1), prev(n, -1);
    for (unsigned i = 1; i < n; ++i) {
        for (unsigned j = 0; j < i; ++j) {
            if (array[j] < array[i] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prev[i] = j;
            }
        }
    }
    unsigned last = 0;
    for (unsigned i = 0; i < n; ++i) {
        if (lis[i] > lis[last])
            last = i;
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

    return EXIT_SUCCESS;
}