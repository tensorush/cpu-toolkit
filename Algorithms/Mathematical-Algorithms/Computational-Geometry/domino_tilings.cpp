/*
    Domino Tilings
    --------------
    Time: O(n*m)
    Space: O(1)
*/
#include <iostream>
#include <numbers>
#include <vector>
#include <cmath>

double DominoTilings(const unsigned& n, const unsigned& m) {
    unsigned numWays = 0;
    if ((n * m) % 2 != 0) return numWays;
    else ++numWays;
    for (unsigned i = n; i > 0; --i) {
        for (unsigned j = m; j > 0; --j) {
            numWays *= std::hypot(2 * std::cos(i * pi_v<double> / (n + 1)),
                                  2 * std::cos(j * pi_v<double> / (m + 1)));
        }
    }
    return std::round(std::sqrt(numWays));
}

int main() {
    unsigned n, m;
    std::cin >> n >> m;
    std::cout << DominoTilings(n, m) << std::endl;

    return EXIT_SUCCESS;
}