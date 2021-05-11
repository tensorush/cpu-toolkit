/*
    Gauss-Jordan Elimination
    ------------------------
    Time: O(n^3)
    Space: O(1)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::string GaussJordanElimination(std::vector<std::vector<double>>& A_b, std::vector<double>& x, const double& EPS = 1e-9) {
	int n = A_b.size(), m = A_b[0].size() - 1;
	std::vector<int> pivotRows(m, -1);
	for (int row = 0, col = 0; row < n && col < m; ++col) {
		// Partial pivoting
        int pivot = row;
		for (int i = row + 1; i < n; ++i) {
			if (fabs(A_b[i][col]) > fabs(A_b[pivot][col])) pivot = i;
        }
		if (fabs(A_b[pivot][col]) < EPS) continue ;
		if (row != pivot) A_b[row].swap(A_b[pivot]);
		pivotRows[col] = row;
        // Reduced row echelon form
        if (fabs(A_b[row][col] - 1) > EPS) {
            for (int j = m; j >= col; --j) {
                A_b[row][j] /= A_b[row][col];
            }
        }
		for (int i = 0; i < n; ++i) {
			if (i != row && fabs(A_b[i][col]) > EPS) {
				for (int j = m; j >= col; --j) {
					A_b[i][j] -= A_b[row][j] * A_b[i][col];
                }
			}
        }
		++row;
	}
    // Solutions
    std::string numSolutions = "Single solution";
	for (const int& pivotRow : pivotRows) {
        if (pivotRow == -1) {
            numSolutions = (A_b[pivotRow][m] < EPS)?("Infinitely many solutions"):("No solutions");
            break;
        } else {
            x.emplace_back(A_b[pivotRow][m]);
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
        for (double& col : row) {
            std::cin >> col;
        }
    }
    std::string solutions = GaussJordanElimination(A_b, x);
    std::cout << solutions << std::endl;
    if (solutions == "Single solution") {
        for (const double& value : x) {
            std::cout << value << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}