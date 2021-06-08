/*
    Second Derivative Formula
    -------------------------
    Error: O(step^4)
*/
#include <functional>
#include <iostream>
#include <cmath>

auto SecondDerivativeFormula(std::function<double (const double&)> Function, const double& x, const double& step = 1e-2) {
    // Using Newton's divided differences interpolation polynomial for five vertices on a uniform grid.
	double value_1 = (-Function(x - 2 * step) + 16 * Function(x - step) - 30 * Function(x) + 16 * Function(x + step) - Function(x + 2 * step)) / (12 * std::pow(step, 2)),
           value_2 = (-Function(x - step) + 16 * Function(x - step / 2) - 30 * Function(x) + 16 * Function(x + step / 2) - Function(x + step)) / (3 * std::pow(step, 2));
	double error = std::abs(4 / 3 * (value_2 - value_1));
	return std::make_pair(value_1, error);
}

int main() {
	double x_0, step;
    std::cin >> x_0 >> step;
    auto Function = [](const double& x) -> double { return std::cosh(x); };
    auto [value, error] = SecondDerivativeFormula(Function, x_0, step);
    std::cout << value << ' ' << error << std::endl;
	
	return EXIT_SUCCESS;
}