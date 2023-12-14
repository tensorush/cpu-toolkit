/*
    Bisection Method
    -----------------
    Convergence: O(n)
*/
#include <functional>
#include <iostream>
#include <cmath>

auto BisectionMethod(std::function<double(const double&)> Function, double low, double high, const double& EPS = 1e-9) {
    unsigned numIterations = 0;
    double mid = low + (high - low) / 2;
    while (Function(mid) != 0 && (high - low) / 2 > EPS) {
        mid = low + (high - low) / 2;
        (Function(low) * Function(mid) > 0) ? (low = mid) : (high = mid);
        ++numIterations;
    }
    return std::make_pair(mid, numIterations);
}

int main() {
    double low, high;
    std::cin >> low >> high;
    auto Function = [](const double& x) -> double {
        return std::pow(x, 2) - 5 * x;
    };
    auto [root, numIterations] = BisectionMethod(Function, low, high);
    std::cout << root << ' ' << numIterations << std::endl;

    return EXIT_SUCCESS;
}