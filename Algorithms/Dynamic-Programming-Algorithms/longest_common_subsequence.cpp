/*
    Longest Common Subsequence
    --------------------------
    Time: O(n*m)
    Space: O(n*m)
*/
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
auto LongestCommonSubsequence(const std::vector<T>& sequence_1, const std::vector<T>& sequence_2) {
    unsigned n = sequence_1.size(), m = sequence_2.size();
    std::vector<std::vector<unsigned>> lcs(n + 1, std::vector<unsigned>(m + 1));
    for (unsigned i = 1; i <= n; ++i) {
        for (unsigned j = 1; j <= m; ++j) {
            lcs[i][j] = (sequence_1[i - 1] == sequence_2[j - 1]) ? (lcs[i - 1][j - 1] + 1) : (std::max(lcs[i - 1][j], lcs[i][j - 1]));
        }
    }
    unsigned maxLCS = lcs[n][m];
    std::vector<T> solution(maxLCS);
    unsigned i = n, j = m;
    while (i > 0 && j > 0) {
        if (sequence_1[i - 1] == sequence_2[j - 1]) {
            solution[maxLCS - 1] = sequence_1[i - 1];
            --maxLCS;
            --i;
            --j;
        } else if (lcs[i - 1][j] > lcs[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    return solution;
}

int main() {
    unsigned n;
    std::cin >> n;
    std::vector<int> sequence_1(n);
    for (int& element : sequence_1) {
        std::cin >> element;
    }
    unsigned m;
    std::cin >> m;
    std::vector<int> sequence_2(m);
    for (int& element : sequence_2) {
        std::cin >> element;
    }
    auto solution = LongestCommonSubsequence(sequence_1, sequence_2);
    for (const int& element : solution) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}