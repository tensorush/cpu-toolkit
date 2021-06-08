/*
    Matrix Search
    -------------
    Time: O(n+m)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template<typename T>
auto MatrixSearch(const std::vector<std::vector<T>>& matrix, const T& key) {
    size_t n = matrix.size(), m = matrix[0].size();
    if (key < matrix[0][0] || key > matrix[n - 1][m - 1]) return std::make_pair(-1, -1);
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
    return std::make_pair(-1, -1);
}

int main() {
    int key;
    unsigned n, m;
    std::cin >> n >> m >> key;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (std::vector<int>& row : matrix) {
        for (int& element : row) {
            std::cin >> element;
        }
    }
    auto [row, col] = MatrixSearch(matrix, key);
    std::cout << row << ' ' << col << std::endl;

    return EXIT_SUCCESS;
}