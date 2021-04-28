/*
    Matrix Rank
    -------------------
    Time: O(max(n,m)^3)
    Space: O(n)
*/
#include <algorithm>
#include <iostream>
#include <vector>

double MatrixRank(std::vector<std::vector<double>>& matrix, const double EPS = 1e-9) {
    size_t n = matrix.size(), m = matrix[0].size();
    size_t rank = std::max(n, m);
    std::vector<bool> rowsVisited(n);
    for (size_t i = 0, j; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            if (!rowsVisited[j] && abs(matrix[j][i]) > EPS) break;
        }
        if (j == n) {
            --rank;
        } else {
            rowsVisited[j] = true;
            for (size_t p = i + 1; p < m; ++p) {
                matrix[j][p] /= matrix[j][i];
            }
            for (size_t k = 0; k < n; ++k) {
                if (k != j && abs (matrix[k][i]) > EPS) {
                    for (size_t p = i + 1; p < m; ++p) {
                        matrix[k][p] -= matrix[j][p] * matrix[k][i];
                    }
                }
            }
        }
    }
    return rank;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    std::vector<std::vector<double>> matrix(n, std::vector<double>(m));
    for (std::vector<double>& row : matrix) {
        for (double& col : row) {
            std::cin >> col;
        }
    }
    std::cout << MatrixRank(matrix) << std::endl;

    return 0;
}