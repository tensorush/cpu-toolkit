/*
    Hessian
    ------------
    Time: O(n*m)
    Space: O(n)
*/
#include <functional>
#include <iostream>
#include <vector>
#include <cmath>

void Hessian(std::function<double(const std::vector<double>&)> Function, const std::vector<double>& point, std::vector<std::vector<double>>& hessian, const double& step = 1e-5) {
    unsigned n = point.size();
    std::vector<double> plusIDeltaPoint, plusJDeltaPoint, plusDoubleDeltaPoint;
    // Approximating second-order derivatives with forward differences.
    // Error: O(step)
    for (unsigned i = 0; i < n; ++i) {
        plusIDeltaPoint = point;
        plusIDeltaPoint[i] += step;
        plusDoubleDeltaPoint = plusIDeltaPoint;
        plusDoubleDeltaPoint[i] *= 2;
        hessian[i][i] = (Function(plusDoubleDeltaPoint) - 2 * Function(plusIDeltaPoint) + Function(point)) / std::pow(step, 2);
    }
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = i + 1; j < n; ++j) {
            plusIDeltaPoint = plusJDeltaPoint = point;
            plusIDeltaPoint[i] += step;
            plusJDeltaPoint[j] += step;
            plusDoubleDeltaPoint = plusIDeltaPoint;
            plusDoubleDeltaPoint[j] += step;
            hessian[i][j] = (Function(plusDoubleDeltaPoint) - Function(plusIDeltaPoint) - Function(plusJDeltaPoint) + Function(point)) / std::pow(step, 2);
        }
    }
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < i; ++j) {
            hessian[i][j] = hessian[j][i];
        }
    }
}

int main() {
    double step;
    unsigned numVariables;
    std::cin >> step >> numVariables;
    std::vector<double> point(numVariables);
    for (double& coordinate : point) {
        std::cin >> coordinate;
    }
    auto Function = [](const std::vector<double>& point) -> double {
        return std::pow(point[0] - point[1], 2);
    };
    std::vector<std::vector<double>> hessian(numVariables, std::vector<double>(numVariables));
    Hessian(Function, point, hessian, step);
    for (const auto& row : hessian) {
        for (const double& secondPartialDerivative : row) {
            std::cout << secondPartialDerivative << ' ';
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}