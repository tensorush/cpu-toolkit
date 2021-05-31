/*
    Travelling Salesman Problem
    ---------------------------
    Time: O(2^n*n^2)
    Space: O(2^n*n)
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

double Distance(const unsigned& a, const unsigned& b, const std::vector<double>& x, const std::vector<double>& y) {
    double dx = x[a] - x[b], dy = y[a] - y[b];
    return sqrt(dx * dx + dy * dy);
}

double TravellingSalesmanProblem(const unsigned& n, const std::vector<double>& x, const std::vector<double>& y) {
    double shortestPath[1 << 10][10];
    for (unsigned mask = 0; mask < (1 << n); ++mask) {
        for (unsigned i = 0; i < n; ++i) {
            shortestPath[mask][i] = INFINITY;
        }
    }
    shortestPath[1][0] = 0;
    for (unsigned mask = 2; mask < (1 << n); ++mask) {
        for (unsigned i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                unsigned mask_without_i = mask ^ (1 << i);
                for (unsigned j = 0; j < n; ++j) {
                    if (j != i && ((mask >> j) & 1)) {
                        shortestPath[mask][i] = std::min(shortestPath[mask][i], shortestPath[mask_without_i][j] + Distance(j, i, x, y));
                    }
                }
            }
        }
    }
    double shortestCycle = INFINITY;
    unsigned mask_all = (1 << n) - 1;
    for (unsigned i = 0; i < n; ++i) {
        shortestCycle = std::min(shortestCycle, shortestPath[mask_all][i] + Distance(i, 0, x, y));
    }
    return shortestCycle;
}

int main() {
    unsigned n;
    std::cin >> n;
    std::vector<double> x(n), y(n);
    for (unsigned i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }
    std::cout << TravellingSalesmanProblem(n, x, y) << std::endl;

    return EXIT_SUCCESS;
}