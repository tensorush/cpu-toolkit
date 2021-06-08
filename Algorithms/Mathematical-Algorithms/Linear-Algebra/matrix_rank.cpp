/*
    Matrix Rank
    -------------------
    Time: O(max(n,m)^3)
    Space: O(1)
*/
#include <iostream>
#include <vector>
#include <cmath>

double MatrixRank(std::vector<std::vector<double>>& matrix, const double& EPS = 1e-9) {
    int n = matrix.size(), m = matrix[0].size();
    int rank = (n < m)?(n):(m);
    for (int row = 0, col = 0; row < n && col < m; ++col) {
        // Pivoting
        if (std::abs(matrix[row][col]) < EPS) {
            for (int pivot = row + 1; pivot < n; ++pivot) {
                if (std::abs(matrix[pivot][col]) > EPS) {
                    matrix[row].swap(matrix[pivot]);
                    break;
                }
            }
            if (std::abs(matrix[row][col]) < EPS) {
                --rank;
                continue;
            }
        }
        // Forward elimination (row echelon form)
        if (std::abs(matrix[row][col] - 1) > EPS) {
            for (int j = m - 1; j >= col; --j) {
                matrix[row][j] /= matrix[row][col];
            }
        }
        for (int i = row + 1; i < n; ++i) {
            if (std::abs(matrix[i][col]) > EPS) {
                for (int j = m - 1; j >= col; --j) {
                    matrix[i][j] -= matrix[row][j] * matrix[i][col];
                }
            }
        }
        ++row;
    }
    return rank;
}

int main() {
    unsigned n, m;
    std::cin >> n >> m;
    std::vector<std::vector<double>> matrix(n, std::vector<double>(m));
    for (std::vector<double>& row : matrix) {
        for (double& element : row) {
            std::cin >> element;
        }
    }
    std::cout << MatrixRank(matrix) << std::endl;

    return EXIT_SUCCESS;
}