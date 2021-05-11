/*
    Ternary Search
    -----------------------
    Time: O(log((r-l)/EPS))
    Space: O(1)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

double f(const double& x) {
    return pow(x - 1, 2);
}

template<typename T>
T TernarySearch(T f(const T&), T left, T right, const T& EPS = 1e-9) {
    while (right - left > EPS) {
        T a = (left * 2 + right) / 3, b = (left + right * 2) / 3;
        (f(a) < f(b))?(right = b):(left = a);
    }
    return (left + right) / 2;
}

int main() {
    double left, right;
    std::cin >> left >> right;
    std::cout << std::setprecision(3) << std::fixed
              << TernarySearch(f, left, right) << std::endl;

    return 0;
}