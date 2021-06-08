/*
    Gaussian Elimination
    --------------------
    Time: O(n^3)
    Space: O(1)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::string GaussianElimination(std::vector<std::vector<double>>& A_b, std::vector<double>& x, const double& EPS = 1e-9) {
	int n = A_b.size(), m = A_b[0].size() - 1;
	std::vector<int> pivotRows(m, -1);
	for (int row = 0, col = 0; row < n && col < m; ++col) {
		// Partial pivoting
        int pivot = row;
		for (int i = row + 1; i < n; ++i) {
			if (std::abs(A_b[i][col]) > std::abs(A_b[pivot][col])) pivot = i;
        }
		if (std::abs(A_b[pivot][col]) < EPS) continue ;
        if (row != pivot) A_b[row].swap(A_b[pivot]);
		pivotRows[col] = row;
        // Forward elimination (row echelon form)
        if (std::abs(A_b[row][col] - 1) > EPS) {
            for (int j = m; j >= col; --j) {
                A_b[row][j] /= A_b[row][col];
            }
        }
		for (int i = row + 1; i < n; ++i) {
            if (std::abs(A_b[i][col]) > EPS) {
                for (int j = m; j >= col; --j) {
                    A_b[i][j] -= A_b[row][j] * A_b[i][col];
                }
            }
        }
		++row;
	}
    // Back substitution
    std::string numSolutions = "Single solution";
	for (int j = m - 1; j >= 0; --j) {
		if (pivotRows[j] == -1) {
            numSolutions = (A_b[j][m] < EPS)?("Infinitely many solutions"):("No solutions");
            break;
        } else {
            double curX = A_b[pivotRows[j]][m];
            for (int col = j + 1, k = x.size() - 1; col < m; ++col, --k) {
                curX -= A_b[pivotRows[j]][col] * x[k];
            }
            x.emplace_back(curX);
        }
    }
	return numSolutions;
}

int main() {
    unsigned n, m;
    std::cin >> n >> m;
    std::vector<double> x;
    std::vector<std::vector<double>> A_b(n, std::vector<double>(m + 1));
    for (std::vector<double>& row : A_b) {
        for (double& element : row) {
            std::cin >> element;
        }
    }
    std::string numSolutions = GaussianElimination(A_b, x);
    std::cout << numSolutions << std::endl;
    if (numSolutions == "Single solution") {
        for (const double& value : x) {
            std::cout << value << ' ';
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}