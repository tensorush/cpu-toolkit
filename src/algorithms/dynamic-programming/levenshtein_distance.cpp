/*
    Levenshtein Distance
    --------------------
    Time: O(n*m)
    Space: O(n*m)
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

int LevenshteinDistance(const std::string& string_1, const std::string& string_2) {
    unsigned n = string_1.size(), m = string_2.size();
    std::vector<std::vector<int>> distances(2, std::vector<int>(m + 1));
    for (unsigned i = 0; i <= n; ++i) {
        for (unsigned j = 0; j <= m; ++j) {
            if (i == 0 || j == 0) {
                distances[i & 1][j] = i + j;
                continue;
            }
            int insert_distance = distances[i & 1][j - 1] + 1;
            int delete_distance = distances[(i - 1) & 1][j] + 1;
            int match_distance = distances[(i - 1) & 1][j - 1] + (string_1[n - i] != string_2[m - j]);
            distances[i & 1][j] = std::min({ insert_distance, delete_distance, match_distance });
        }
    }
    return distances[n & 1][m];
}

int main() {
    std::string string_1, string_2;
    std::cin >> string_1 >> string_2;
    std::cout << LevenshteinDistance(string_1, string_2) << std::endl;

    return EXIT_SUCCESS;
}
