/*
    Runge-Kutta Method
    ------------------
    Time: O(numSteps)
    Space: O(1)
*/
#include <functional>
#include <iostream>
#include <vector>
#include <cmath>

void RungeKuttaMethod(std::function<double (const double&, const double&)> Function, double x, double y, const double& start, const double& end, const double& step, std::vector<std::pair<double, double>>& solutions) {
    double k_1, k_2, k_3, k_4;
    unsigned numSteps = std::ceil((end - start) / step);
    for (unsigned i = 0; i < numSteps; ++i) {
        k_1 = step * Function(x, y);
        k_2 = step * Function(x + step / 2, y + k_1 / 2);
        k_3 = step * Function(x + step / 2, y + k_2 / 2);
        k_4 = step * Function(x + step, y + k_3 );
        y += (k_1 + 2 * k_2 + 2 * k_3 + k_4) / 6;
        x += step;
        solutions.emplace_back(std::make_pair(x, y));
    }
}

int main() {
    double x_0, y_0, start, end, step;
    std::cin >> x_0 >> y_0 >> start >> end >> step;
    std::vector<std::pair<double, double>> solutions;
    solutions.emplace_back(std::make_pair(x_0, y_0));
    auto Function = [](const double& x, const double& y) -> double { return std::pow(x, 2) * (y + std::exp(std::pow(x, 3))); };
    RungeKuttaMethod(Function, x_0, y_0, start, end, step, solutions);
    for (const auto& solution : solutions) {
        std::cout << "x = " << solution.first << " y = " << solution.second << std::endl;
    }

    return EXIT_SUCCESS;
}