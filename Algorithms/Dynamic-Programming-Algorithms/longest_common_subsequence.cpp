/*
    Longest Common Subsequence
    --------------------------
    Time: O(n*m)
    Space: O(n*m)
*/
#include <algorithm>
#include <iostream>
#include <vector>

template<typename T>
auto LongestCommonSubsequence(const std::vector<T>& a, const std::vector<T>& b) {
    std::vector<std::vector<size_t>> lcs(a.size() + 1, std::vector<size_t>(b.size() + 1));
    for (size_t i = 1; i <= a.size(); ++i) {
        for (size_t j = 1; j <= b.size(); ++j) {
            if (a[i - 1] == b[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else {
                lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
    size_t maxLCS = lcs[a.size()][b.size()];
    std::vector<T> solution(maxLCS);
    size_t i = a.size(), j = b.size();
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            solution[maxLCS - 1] = a[i - 1];
            --maxLCS; --i; --j;
        } else if (lcs[i - 1][j] > lcs[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    return solution;
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> a(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    size_t m;
    std::cin >> m;
    std::vector<int> b(m);
    for (size_t j = 0; j < m; ++j) {
        std::cin >> b[j];
    }
    auto solution = LongestCommonSubsequence(a, b);
    for (auto element : solution) {
        std::cout << element << ' ';
    }

    return 0;
}