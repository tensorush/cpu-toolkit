/*
    Newton's Method
    -------------------
    Error: O(1)
    Convergence: O(n^2)
*/
#include <functional>
#include <iostream>
#include <cmath>

auto NewtonMethod(std::function<double (const double&)> Function, std::function<double (const double&)> functionDerivative, double x, const double& EPS = 1e-9) {
    double x_prev;
    unsigned numIterations = 0;
    do {
        x_prev = x;
        x -= Function(x) / functionDerivative(x);
        ++numIterations;
    } while (std::abs(x - x_prev) > EPS);
    return std::make_pair(x, numIterations);
}

int main() {
    double x_0;
    std::cin >> x_0;
    auto Function = [](const double& x) -> double { return std::pow(x, 2); };
    auto functionDerivative = [](const double& x) -> double { return 2 * x; };
    auto [root, numIterations] = NewtonMethod(Function, functionDerivative, x_0);
    std::cout << root << ' ' << numIterations << std::endl;

    return EXIT_SUCCESS;
}