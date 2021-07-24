/*
    Nonlinear Conjugate Gradient Methods
    -------------------------------------------------
    | Fletcher–Reeves Method | Polak–Ribière Method |
    -------------------------------------------------
    | Time: O(n^3)           |         O(n^3)       |
    | Space: O(n)            |          O(n)        |
    -------------------------------------------------
*/
#include <functional>
#include <iostream>
#include <vector>
#include <cmath>

enum class Method {
    FletcherReeves = 0, PolakRibiere = 1
};

// Vector negation
auto operator-(const std::vector<double>& U) {
    unsigned n = U.size();
    std::vector<double> W(n);
    for (unsigned i = 0; i < n; ++i) {
        W[i] -= U[i];
    }
    return W;
}

// Vector addition
auto operator+(const std::vector<double>& U, const std::vector<double>& V) {
    unsigned n = U.size();
    std::vector<double> W(n);
    for (unsigned i = 0; i < n; ++i) {
        W[i] = U[i] + V[i];
    }
    return W;
}

// Vector subtraction
auto operator-(const std::vector<double>& U, const std::vector<double>& V) {
    unsigned n = U.size();
    std::vector<double> W(n);
    for (unsigned i = 0; i < n; ++i) {
        W[i] = U[i] - V[i];
    }
    return W;
}

// Inner product
double operator*(const std::vector<double>& U, const std::vector<double>& V) {
    unsigned n = U.size();
    double innerProduct = 0;
    for (unsigned i = 0; i < n; ++i) {
        innerProduct += U[i] * V[i];
    }
    return innerProduct;
}

// Vector by scalar multiplication
auto operator*(const double& alpha, const std::vector<double>& U) {
    unsigned n = U.size();
    std::vector<double> V(n);
    V = U;
    for (double& coordinate : V) {
        coordinate *= alpha;
    }
    return V;
}

double FindMinimum(std::function<double(const std::vector<double>&)> Function, std::vector<double>& x, std::vector<double>& p, const double& EPS = 1e-9) {
    double a = 0, b = 1e5, x_0 = a + 0.5 * (3 - std::sqrt(5)) * (b - a), x_1 = b - x_0 + a;
    while (std::abs(b - a) > EPS) {
        (Function(x + x_0 * p) < Function(x + x_1 * p)) ? (b = x_1) : (a = x_0);
        x_1 = x_0;
        x_0 = b + a - x_1;
    }
    return a + (b - a) / 2;
}

unsigned ConjugateGradientMethods(const Method& method, std::vector<double>& x, std::function<double(const std::vector<double>&)> Function, std::function<std::vector<double>(const std::vector<double>&)> FunctionGradient, const double& EPS = 1e-9) {
    // TODO: Add Hestenes-Stiefel and Dai–Yuan methods
    std::vector<double> p, gradient, newGradient;
    unsigned dimension = x.size(), numIterations = 0;
    double alpha, beta, gradientSquare, newGradientSquare, curValue = Function(x), prevValue = curValue;
    switch (method) {
        case Method::FletcherReeves:
            p = -FunctionGradient(x);
            gradientSquare = p * p;
            while (gradientSquare > EPS) {
                alpha = FindMinimum(Function, x, p);
                x = x + alpha * p;
                newGradient = -FunctionGradient(x);
                newGradientSquare = newGradient * newGradient;
                beta = (numIterations % (5 * dimension) == 0) ? (0) : (newGradientSquare / gradientSquare);
                p = newGradient + beta * p;
                prevValue = curValue;
                curValue = Function(x);
                gradientSquare = newGradientSquare;
                ++numIterations;
            }
            break;
        case Method::PolakRibiere:
            p = FunctionGradient(x);
            gradient = -p;
            gradientSquare = p * p;
            while (gradientSquare > EPS) {
                alpha = FindMinimum(Function, x, p);
                x = x + alpha * p;
                newGradient = -FunctionGradient(x);
                newGradientSquare = newGradient * newGradient;
                beta = (numIterations % (5 * dimension) == 0) ? (0) : (-(newGradientSquare - (newGradient * gradient)) / gradientSquare);
                p = newGradient + beta * p;
                prevValue = curValue;
                curValue = Function(x);
                gradient = newGradient;
                gradientSquare = newGradientSquare;
                ++numIterations;
            }
    }
    return numIterations;
}

int main() {
    unsigned method;
    std::cin >> method;
    std::vector<double> x(2);
    auto Function = [](const std::vector<double>& x) -> double {
        return (x[0] - 5) * (x[0] - 5) * (x[1] - 4) * (x[1] - 4) + (x[0] - 5) * (x[0] - 5) + (x[1] - 4) * (x[1] - 4) + 1;
    };
    auto FunctionGradient = [](const std::vector<double>& x) -> std::vector<double> {
        return { 2 * (x[0] - 5) * ((x[1] - 4) * (x[1] - 4) + 1), 2 * (x[1] - 4) * ((x[0] - 5) * (x[0] - 5) + 1) };
    };
    unsigned numIterations = ConjugateGradientMethods(static_cast<Method>(method), x, Function, FunctionGradient);
    std::cout << numIterations << ' ' << Function(x) << std::endl;
    for (const double& value : x) {
        std::cout << value << ' ';
    }

    return EXIT_SUCCESS;
}