/*
    Matrix Transpose
    ----------------
    Time: O(n^2)
    Space: O(1)
*/
#include <iostream>
#include <vector>
#include <cmath>

void MatrixTranspose(const std::vector<std::vector<double>>& matrix, std::vector<std::vector<double>>& transpose) {
    int n = matrix.size(), m = matrix[0].size();
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            transpose[col][row] = matrix[row][col];
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

    return 0;
}