/*
    Staircase Problem
    -------------------
    Time: O(k^3 log(n))
    Space: O(k^2)
*/
#include <iostream>
#include <vector>

auto MatrixMultiplication(const std::vector<std::vector<unsigned>>& A, const std::vector<std::vector<unsigned>>& B) {
    size_t n = A.size(), m = B[0].size(), l = B.size();
    std::vector<std::vector<unsigned>> C(n, std::vector<unsigned>(n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            for (size_t k = 0; k < l; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

auto MatrixExponentiation(std::vector<std::vector<unsigned>>& A, unsigned power) {
    size_t n = A.size();
    std::vector<std::vector<unsigned>> B(n, std::vector<unsigned>(n));
    for (size_t i = 0; i < n; ++i) {
        B[i][i] = 1;
    }
    while (power) {
        if (power % 2 == 1) B = MatrixMultiplication(B, A);
        A = MatrixMultiplication(A, A);
        power /= 2;
    }
    return B;
}
 
unsigned StaircaseProblem(const unsigned& n, const unsigned& k = 3) {
    std::vector<unsigned> baseWays = {0, 1, 2, 4};
    if (n < 4) return baseWays[n];
    std::vector<std::vector<unsigned>> recurrence(k + 1, std::vector<unsigned>(k + 1));
    for (unsigned i = 1; i < k; ++i) {
        for (unsigned j = 1; j <= k; ++j) {
            if (i == j - 1) recurrence[i][j] = 1;
        }
    }
    recurrence[k].assign(k + 1, 1);
    recurrence = MatrixExponentiation(recurrence, n - 1);
    unsigned numWays = 0;
    for (unsigned j = 1; j <= k; ++j) {
        numWays += recurrence[1][j] * baseWays[j];
    }
    return numWays;
}

int main() {
    unsigned numSteps;
    std::cin >> numSteps;
    std::cout << StaircaseProblem(numSteps) << std::endl;
    
    return EXIT_SUCCESS;
}