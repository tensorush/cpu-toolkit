/*
    Runge-Kutta Methods
    --------------------------------------------------------------------------------------------
    | Euler Method   | Ralston's Method | Midpoint Method | Heun's Method | Runge-Kutta Method |
    --------------------------------------------------------------------------------------------
    | Error: O(step) |     O(step^2)    |    O(step^2)    |   O(step^2)   |      O(step^4)     |
    --------------------------------------------------------------------------------------------
*/
#include <functional>
#include <iostream>
#include <vector>
#include <cmath>

enum class Method {
    Euler = 0, Ralston = 1, Midpoint = 2, Heun = 3, RungeKutta = 4
};

void RungeKuttaMethods(const Method& method, std::function<double(const double&, const double&)> Function, double x, double y, const double& start, const double& end, const double& step, std::vector<std::pair<double, double>>& solutions) {
    unsigned numSteps = std::ceil((end - start) / step);
    double k_1, k_2, k_3, k_4, curValue, halfStep = step / 2;
    switch (method) {
        case Method::Euler:
            for (unsigned i = 0; i < numSteps; ++i) {
                y += step * Function(x, y);
                x += step;
                solutions.emplace_back(std::make_pair(x, y));
            }
            break;
        case Method::Ralston:
            for (unsigned i = 0; i < numSteps; ++i) {
                k_1 = step * Function(x, y);
                k_2 = step * Function(x + 2 * step / 3, y + 2 * k_1 / 3);
                y += (k_1 + 3 * k_2) / 4;
                x += step;
                solutions.emplace_back(std::make_pair(x, y));
            }
            break;
        case Method::Midpoint:
            for (unsigned i = 0; i < numSteps; ++i) {
                y += step * Function(x + halfStep, y + halfStep * Function(x, y));
                x += step;
                solutions.emplace_back(std::make_pair(x, y));
            }
            break;
        case Method::Heun:
            for (unsigned i = 0; i < numSteps; ++i) {
                curValue = Function(x, y);
                y += halfStep * (curValue + Function(x + step, y + step * curValue));
                x += step;
                solutions.emplace_back(std::make_pair(x, y));
            }
            break;
        case Method::RungeKutta:
            for (unsigned i = 0; i < numSteps; ++i) {
                k_1 = step * Function(x, y);
                k_2 = step * Function(x + halfStep, y + k_1 / 2);
                k_3 = step * Function(x + halfStep, y + k_2 / 2);
                k_4 = step * Function(x + step, y + k_3);
                y += (k_1 + 2 * k_2 + 2 * k_3 + k_4) / 6;
                x += step;
                solutions.emplace_back(std::make_pair(x, y));
            }
    }
}

int main() {
    unsigned method;
    double x_0, y_0, start, end, step;
    std::cin >> method >> x_0 >> y_0 >> start >> end >> step;
    std::vector<std::pair<double, double>> solutions;
    solutions.emplace_back(std::make_pair(x_0, y_0));
    auto Function = [](const double& x, const double& y) -> double {
        return std::pow(x, 2) * (y + std::exp(std::pow(x, 3)));
    };
    RungeKuttaMethods(static_cast<Method>(method), Function, x_0, y_0, start, end, step, solutions);
    for (const auto& solution : solutions) {
        std::cout << "x = " << solution.first << " y = " << solution.second << std::endl;
    }

    return EXIT_SUCCESS;
}