/*
    Golden-Section Search
    -----------------------
    Time: O(log(EPS/(r-l)))
    Space: O(1)
*/
#include <functional>
#include <iostream>
#include <numbers>
#include <cmath>

double GoldenSectionSearch(std::function<double(const double&)> Function, double left, double right, const double& EPS = 1e-9) {
    double length = right - left;
    if (length <= EPS)
        return left + (right - left) / 2;
    double inversePhi = 1 / std::numbers::phi_v<double>, inversePhiSquare = std::pow(inversePhi, 2),
           newLeft = left + inversePhiSquare * length, newRight = left + inversePhi * length,
           yNewLeft = Function(newLeft), yNewRight = Function(newRight);
    int numIterations = std::ceil(std::log(EPS / length) / std::log(inversePhi));
    while (--numIterations) {
        if (yNewLeft < yNewRight) {
            right = newRight;
            newRight = newLeft;
            yNewRight = yNewLeft;
            length *= inversePhi;
            newLeft = left + inversePhiSquare * length;
            yNewLeft = Function(newLeft);
        } else {
            left = newLeft;
            newLeft = newRight;
            yNewLeft = yNewRight;
            length *= inversePhi;
            newRight = left + inversePhi * length;
            yNewRight = Function(newRight);
        }
    }
    return (yNewLeft < yNewRight) ? (left + (newRight - left) / 2) : (newLeft + (right - newLeft) / 2);
}

int main() {
    double left, right;
    std::cin >> left >> right;
    auto Function = [](const double& x) -> double {
        return std::pow(x - 2, 2);
    };
    std::cout << GoldenSectionSearch(Function, left, right) << std::endl;

    return EXIT_SUCCESS;
}
