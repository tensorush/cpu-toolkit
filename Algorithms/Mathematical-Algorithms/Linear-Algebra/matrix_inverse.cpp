/*
    Matrix Inverse
    --------------
    Time: O(n^3)
    Space: O(1)
*/
#include <iostream>
#include <vector>
#include <cmath>

bool MatrixInverse(std::vector<std::vector<double>>& matrix, std::vector<std::vector<double>>& inverse, const double& EPS = 1e-9) {
    bool isInverse = true;
    int n = matrix.size();
    for (int row = 0, col = 0; row < n; ++row, ++col) {
        // Partial pivoting
        int pivot = row;
        for (int i = row + 1; i < n; ++i) {
            if (abs(matrix[i][col]) > abs(matrix[pivot][col])) pivot = i;
        }
        if (abs(matrix[pivot][col]) < EPS) {
            isInverse = false;
            break;
        }
        if (row != pivot) {
            matrix[row].swap(matrix[pivot]);
            inverse[row].swap(inverse[pivot]);
        }
        // Reduced row echelon form
        if (abs(matrix[row][col] - 1) > EPS) {
            for (int j = n - 1; j >= 0; --j) {
                inverse[row][j] /= matrix[row][col];
            }
            for (int j = n - 1; j >= col; --j) {
                matrix[row][j] /= matrix[row][col];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i != row && abs(matrix[i][col]) > EPS) {
                for (int j = n - 1; j >= 0; --j) {
                    inverse[i][j] -= inverse[row][j] * matrix[i][col];
                }
                for (int j = n - 1; j >= col; --j) {
                    matrix[i][j] -= matrix[row][j] * matrix[i][col];
                }
            }
        }
    }
    return isInverse;
}

int main() {
    unsigned n;
    std::cin >> n;
    std::vector<std::vector<double>> matrix(n, std::vector<double>(n)), inverse(n, std::vector<double>(n));
    for (std::vector<double>& row : matrix) {
        for (double& col : row) {
            std::cin >> col;
        }
    }
    for (unsigned i = 0; i < n; ++i) {
        inverse[i][i] = 1;
    }
    bool isInverse = MatrixInverse(matrix, inverse);
    if (isInverse) {
        for (std::vector<double>& row : inverse) {
            for (double& col : row) {
                std::cout << col << ' ';
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "Matrix is singular" << std::endl;
    }

    return EXIT_SUCCESS;
}