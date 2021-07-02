/*
    Polynomial Solver
    ----------------------------------------
    | Linear Equation | Quadratic Equation |
    ----------------------------------------
    | Time: O(1)      |        O(1)        |
    | Space: O(1)     |        O(1)        |
    ----------------------------------------
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

enum class Equation {
    Linear = 1, Quadratic = 2
};

auto PolynomialSolver(const Equation& equation, const std::vector<double>& polynomial) {
    // TODO: Add cubic, quartic, quintic and arbitrary-degree equation solvers with complex solutions
    std::vector<double> solutions;
    std::string numSolutions = "Finitely many solutions";
    switch (equation) {
        case Equation::Quadratic:
            if (polynomial[2] != 0) {
                double mean = -polynomial[1] / polynomial[2] / 2, squaredDistance = mean * mean - polynomial[0] / polynomial[2];
                if (squaredDistance > 0) {
                    double distance = std::sqrt(squaredDistance);
                    solutions.emplace_back(mean + distance);
                    solutions.emplace_back(mean - distance);
                } else if (squaredDistance == 0) {
                    solutions.emplace_back(mean);
                } else {
                    numSolutions = "No real solutions";
                }
                break;
            }
        case Equation::Linear:
            if (polynomial[1] != 0)
                solutions.emplace_back(-polynomial[0] / polynomial[1]);
            else
                numSolutions = (polynomial[0] == 0) ? ("Infinitely many solutions") : ("No solutions");
    }
    return std::make_pair(numSolutions, solutions);
}

int main() {
    unsigned n;
    std::cin >> n;
    std::vector<double> polynomial(n + 1);
    for (double& coefficient : polynomial) {
        std::cin >> coefficient;
    }
    auto [numSolutions, solutions] = PolynomialSolver(static_cast<Equation>(n), polynomial);
    std::cout << numSolutions << std::endl;
    if (numSolutions == "Finitely many solutions") {
        for (const double& solution : solutions) {
            std::cout << solution << ' ';
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}