/*
    Matrix Determinant
    ------------------
    Time: O(n^3)
    Space: O(1)
*/
#include <iostream>
#include <vector>

double MatrixDeterminant(std::vector<std::vector<double>>& matrix, const double& EPS = 1e-9) {
    double det = 1;
    size_t n = matrix.size();
    for (size_t i = 0; i < n; ++i) {
        size_t k = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (abs(matrix[j][i]) > abs(matrix[k][i])) k = j;
        }
        if (abs(matrix[k][i]) < EPS) return 0;
        std::swap (matrix[i], matrix[k]);
        if (i != k) det = -det;
        det *= matrix[i][i];
        for (size_t j = i + 1; j < n; ++j) {
            matrix[i][j] /= matrix[i][i];
        }
        for (size_t j = 0; j < n; ++j) {
            if (j != i && abs(matrix[j][i]) > EPS) {
                for (size_t k = i + 1; k < n; ++k) {
                    matrix[j][k] -= matrix[i][k] * matrix[j][i];
                }
            }
        }
    }
    return det;
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<std::vector<double>> matrix(n, std::vector<double>(n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << MatrixDeterminant(matrix) << std::endl;

    return 0;
}