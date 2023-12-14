/*
    Linear Conjugate Gradient Method
    --------------------------------
    Time: O(n^3)
    Space: O(n)
*/
#include <iostream>
#include <vector>

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

// Matrix by vector multiplication
auto operator*(const std::vector<std::vector<double>>& A, const std::vector<double>& U) {
    unsigned n = A.size();
    std::vector<double> V(n);
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < n; ++j) {
            V[i] += A[i][j] * U[j];
        }
    }
    return V;
}

unsigned LinearConjugateGradientMethod(const std::vector<std::vector<double>>& A, std::vector<double>& x, const std::vector<double>& b, const double& EPS = 1e-9) {
    // Using preconditioning for faster convergence
    unsigned numIterations = 0;
    std::vector<double> temp, rNew, r = b, p = r;
    double alpha, beta, rNewSquare, rSquare = r * r;
    while (rSquare > EPS) {
        temp = A * p;
        alpha = rSquare / (temp * p);
        x = x + alpha * p;
        rNew = r - alpha * temp;
        rNewSquare = rNew * rNew;
        beta = rNewSquare / rSquare;
        r = rNew;
        rSquare = rNewSquare;
        p = r + beta * p;
        ++numIterations;
    }
    return numIterations;
}

int main() {
    unsigned n;
    std::cin >> n;
    std::vector<std::vector<double>> A(n, std::vector<double>(n));
    for (std::vector<double>& row : A) {
        for (double& element : row) {
            std::cin >> element;
        }
    }
    std::vector<double> x(n), b(n);
    for (double& element : b) {
        std::cin >> element;
    }
    unsigned numIterations = LinearConjugateGradientMethod(A, x, b);
    std::cout << numIterations << std::endl;
    for (const double& value : x) {
        std::cout << value << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}