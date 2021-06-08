/*
    Riemann Sum
    -------------------------
    Time: O(end-start/deltaX)
    Space: O(1)
*/
#include <functional>
#include <iostream>
#include <cmath>

double RiemannSum(std::function<double (const double&)> Function, const double& a, const double& b, const double& deltaX) {
    double x, sum = 0;
	for (x = a + deltaX * 0.5; x < b; x += deltaX) {
		sum += Function(x);
    }
	return sum * deltaX;
}

int main() {
    double start, end, deltaX;
    std::cin >> start >> end >> deltaX;
    auto Function = [](const double& x) -> double { return std::cosh(x); };
    std::cout << RiemannSum(Function, start, end, deltaX) << std::endl;

    return EXIT_SUCCESS;
}