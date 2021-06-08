/*
    Secant Method
    ---------------------
    Error: O(1)
    Convergence: O(1.618)
*/
#include <functional>
#include <iostream>
#include <cmath>

auto SecantMethod(std::function<double (const double&)> Function, double x_prev, double x, const double& EPS = 1e-9) {
    double temp;
    unsigned numIterations = 0;
    while (std::abs(x - x_prev) > EPS) {
        temp = x;
        x -= Function(x) * (x - x_prev) / (Function(x) - Function(x_prev));
        x_prev = temp;
        ++numIterations;
    }
    return std::make_pair(x, numIterations);
}

int main() {
    double x_0, x_1;
    std::cin >> x_0 >> x_1;
    auto Function = [](const double& x) -> double { return std::pow(x, 2); };
    auto [root, numIterations] = SecantMethod(Function, x_0, x_1);
    std::cout << root << ' ' << numIterations << std::endl;

    return EXIT_SUCCESS;
}