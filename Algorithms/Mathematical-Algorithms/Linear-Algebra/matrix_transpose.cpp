/*
    Matrix Transpose
    ----------------
    Time: O(n^2)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template <typename T>
void MatrixTranspose(const std::vector<std::vector<T>>& matrix, std::vector<std::vector<T>>& transpose) {
    unsigned n = matrix.size(), m = matrix[0].size();
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < m; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    unsigned n, m;
    std::cin >> n >> m;
    std::vector<std::vector<double>> matrix(n, std::vector<double>(m)), transpose(m, std::vector<double>(n));
    for (std::vector<double>& row : matrix) {
        for (double& element : row) {
            std::cin >> element;
        }
    }
    MatrixTranspose(matrix, transpose);
    for (std::vector<double>& row : transpose) {
        for (double& element : row) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}