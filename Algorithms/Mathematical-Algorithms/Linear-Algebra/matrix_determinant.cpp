/*
    Matrix Determinant
    ------------------
    Time: O(n^3)
    Space: O(1)
*/
#include <iostream>
#include <vector>
#include <cmath>

double MatrixDeterminant(std::vector<std::vector<double>>& matrix, const double& EPS = 1e-9) {
    double det = 1;
    int n = matrix.size();
    for (int row = 0, col = 0; row < n; ++row, ++col) {
        // Partial pivoting
        int pivot = row;
        for (int i = row + 1; i < n; ++i) {
            if (abs(matrix[i][col]) > abs(matrix[pivot][col])) pivot = i;
        }
        if (abs(matrix[pivot][col]) < EPS) {
            det = 0;
            break;
        }
        if (row != pivot) {
            matrix[row].swap(matrix[pivot]);
            det *= -matrix[row][col];
        } else {
            det *= matrix[row][col];
        }
        // Reduced row echelon form
        if (abs(matrix[row][col] - 1) > EPS) {
            for (int j = n - 1; j >= col; --j) {
                matrix[row][j] /= matrix[row][col];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i != row && abs(matrix[i][col]) > EPS) {
                for (int j = n - 1; j >= col; --j) {
                    matrix[i][j] -= matrix[row][j] * matrix[i][col];
                }
            }
        }
    }
    return det;
}

int main() {
    unsigned n;
    std::cin >> n;
    std::vector<std::vector<double>> matrix(n, std::vector<double>(n));
    for (std::vector<double>& row : matrix) {
        for (double& col : row) {
            std::cin >> col;
        }
    }
    std::cout << MatrixDeterminant(matrix) << std::endl;

    return EXIT_SUCCESS;
}