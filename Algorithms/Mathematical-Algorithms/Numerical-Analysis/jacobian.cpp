/*
    Jacobian
    ------------
    Time: O(n*m)
    Space: O(n)
*/
#include <functional>
#include <iostream>
#include <vector>
#include <cmath>

enum class Difference {Forward, Central, Backward};

void Jacobian(const Difference& difference, std::vector<std::function<double (const std::vector<double>&)>> components, const std::vector<double>& point, std::vector<std::vector<double>>& jacobian, const double& step = 1e-5) {
    unsigned n = components.size(), m = point.size();
    std::vector<double> deltaPoint, plusDeltaPoint, minusDeltaPoint;
    switch (difference) {
        case Difference::Forward:
            // Approximating first-order derivatives with forward differences.
            // Error: O(step)
            for (unsigned i = 0; i < n; ++i) {
                for (unsigned j = 0; j < m; ++j) {
                    deltaPoint = point;
                    deltaPoint[j] += step;
                    jacobian[i][j] = (components[i](deltaPoint) - components[i](point)) / step;
                }
            }
            break;
        case Difference::Central:
            // Approximating first-order derivatives with central differences.
            // Error: O(step^2)
            for (unsigned i = 0; i < n; ++i) {
                for (unsigned j = 0; j < m; ++j) {
                    plusDeltaPoint = minusDeltaPoint = point;
                    plusDeltaPoint[j] += step;
                    minusDeltaPoint[j] -= step;
                    jacobian[i][j] = (components[i](plusDeltaPoint) - components[i](minusDeltaPoint)) / 2 * step;
                }
            }
            break;
        case Difference::Backward:
            // Approximating first-order derivatives with backward differences.
            // Error: O(step)
            for (unsigned i = 0; i < n; ++i) {
                for (unsigned j = 0; j < m; ++j) {
                    deltaPoint = point;
                    deltaPoint[j] -= step;
                    jacobian[i][j] = (components[i](point) - components[i](deltaPoint)) / step;
                }
            }
    }
}

int main() {
    double step;
    unsigned difference, numComponents, numVariables;
    std::cin >> step >> difference >> numComponents >> numVariables;
    std::vector<double> point(numVariables);
    for (double& coordinate : point) {
        std::cin >> coordinate;
    }
    auto component_1 = [](const std::vector<double>& point) -> double { return std::pow(point[0] + point[1], 2); };
    auto component_2 = [](const std::vector<double>& point) -> double { return std::cosh(point[1] - point[0]); };
    std::vector<std::function<double (const std::vector<double>&)>> components = {component_1, component_2};
    std::vector<std::vector<double>> jacobian(numComponents, std::vector<double>(numVariables));
    Jacobian(static_cast<Difference>(difference), components, point, jacobian, step);
    for (const auto& row : jacobian) {
        for (const double& partialDerivative : row) {
            std::cout << partialDerivative << ' ';
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}