/*
    Travelling Salesman Problem
    ---------------------------
    Time: O(2^n*n^2)
    Space: O(2^n*n)
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>

double Distance(const size_t& a, const size_t& b, const std::vector<double>& x, const std::vector<double>& y) {
    double dx = x[a] - x[b], dy = y[a] - y[b];
    return sqrt(dx * dx + dy * dy);
}

double TravellingSalesmanProblem(const size_t& n, const std::vector<double>& x, const std::vector<double>& y) {
    double shortestPath[1 << 10][10];
    for (size_t mask = 0; mask < (1 << n); ++mask) {
        for (size_t i = 0; i < n; ++i) {
            shortestPath[mask][i] = INFINITY;
        }
    }
    shortestPath[1][0] = 0;
    for (size_t mask = 2; mask < (1 << n); ++mask) {
        for (size_t i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                size_t mask_without_i = mask ^ (1 << i);
                for (size_t j = 0; j < n; ++j) {
                    if (j != i && ((mask >> j) & 1)) {
                        shortestPath[mask][i] = std::min(shortestPath[mask][i], shortestPath[mask_without_i][j] + Distance(j, i, x, y));
                    }
                }
            }
        }
    }
    double shortestCycle = INFINITY;
    size_t mask_all = (1 << n) - 1;
    for (size_t i = 0; i < n; ++i) {
        shortestCycle = std::min(shortestCycle, shortestPath[mask_all][i] + Distance(i, 0, x, y));
    }
    return shortestCycle;
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<double> x(n), y(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }
    std::cout << TravellingSalesmanProblem(n, x, y) << std::endl;
}