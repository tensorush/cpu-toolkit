/*
    Matrix Search
    -------------
    Time: O(n+m)
    Space: O(1)
*/
#include <iostream>
#include <utility>
#include <vector>

template<typename T>
std::pair<int, int> MatrixSearch(const std::vector<std::vector<T>>& matrix, const T& key) {
    size_t n = matrix.size(), m = matrix[0].size();
    if (key < matrix[0][0] || key > matrix[n - 1][m - 1]) return {-1, -1};
    size_t row = 0, col = m - 1;
    while (row <= n - 1 && col >= 0) {
        if (matrix[row][col] < key) {
            ++row;
        } else if (matrix[row][col] > key) {
            --col;
        } else {
            return {row, col};
        }
    }
    return {-1, -1};
}

int main() {
    int key;
    size_t n, m;
    std::cin >> n >> m >> key;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    auto row_col = MatrixSearch(matrix, key);
    std::cout << row_col.first << row_col.second << std::endl;

    return 0;
}