/*
    Matrix Transpose
    ----------------
    Time: O(n^2)
    Space: O(1)
*/
#include <iostream>
#include <vector>
#include <cmath>

template<typename T>
void MatrixTranspose(const std::vector<std::vector<T>>& matrix, std::vector<std::vector<T>>& transpose) {
    size_t n = matrix.size(), m = matrix[0].size();
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    unsigned n, m;
    std::cin >> n >> m;
    std::vector<std::vector<double>> matrix(n, std::vector<double>(m)), transpose(m, std::vector<double>(n));
    for (std::vector<double>& row : matrix) {
        for (double& col : row) {
            std::cin >> col;
        }
    }
    MatrixTranspose(matrix, transpose);
    for (std::vector<double>& row : transpose) {
        for (double& col : row) {
            std::cout << col << ' ';
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}