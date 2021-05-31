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

int LevensteinDistance(const std::string& string_1, const std::string& string_2) {
    size_t size_1 = string_1.size(), size_2 = string_2.size();
    std::vector<std::vector<int>> distances(2, std::vector<int>(size_2 + 1));
    for (size_t i = 0; i <= size_1; ++i) {
        for (size_t j = 0; j <= size_2; ++j) {
            if (i == 0 || j == 0) {
                distances[i & 1][j] = i + j;
                continue;
            }
            int insert_distance = distances[i & 1][j - 1] + 1;
            int delete_distance = distances[(i - 1) & 1][j] + 1;
            int match_distance = distances[(i - 1) & 1][j - 1] + (string_1[size_1 - i] != string_2[size_2 - j]);
            distances[i & 1][j] = std::min({ insert_distance, delete_distance, match_distance });
        }
    }
    return distances[size_1 & 1][size_2];
}

int main() {
    std::string string_1, string_2;
    std::cin >> string_1 >> string_2;
    std::cout << LevensteinDistance(string_1, string_2) << std::endl;

    return EXIT_SUCCESS;
}