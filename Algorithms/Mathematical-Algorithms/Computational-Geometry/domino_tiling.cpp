/*
    Domino Tiling
    ---------------------
    Time: O(width*length)
    Space: O(1)
*/
#include <iostream>
#include <numbers>
#include <vector>
#include <cmath>

unsigned DominoTiling(const unsigned& width, const unsigned& length) {
    unsigned numWays = 0;
    if ((width * length) % 2 != 0)
        return numWays;
    else
        ++numWays;
    for (unsigned i = width; i > 0; --i) {
        for (unsigned j = length; j > 0; --j) {
            numWays *= std::hypot(2 * std::cos(i * pi_v<double> / (width + 1)),
                2 * std::cos(j * pi_v<double> / (length + 1)));
        }
    }
    return std::round(std::sqrt(numWays));
}

int main() {
    unsigned width, length;
    std::cin >> width >> length;
    std::cout << DominoTiling(width, length) << std::endl;

    return EXIT_SUCCESS;
}