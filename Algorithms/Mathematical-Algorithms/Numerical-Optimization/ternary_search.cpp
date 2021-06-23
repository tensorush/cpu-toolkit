/*
    Ternary Search
    -----------------------
    Time: O(log((r-l)/EPS))
    Space: O(1)
*/
#include <functional>
#include <iostream>
#include <cmath>

double TernarySearch(std::function<double(const double &)> Function, double left, double right, const double &EPS = 1e-9)
{
    while (right - left > EPS)
    {
        double a = (left * 2 + right) / 3, b = (left + right * 2) / 3;
        (Function(a) < Function(b)) ? (right = b) : (left = a);
    }
    return (left + right) / 2;
}

int main()
{
    double left, right;
    std::cin >> left >> right;
    auto Function = [](const double &x) -> double
    {
        return -std::pow(x, 2);
    };
    std::cout << TernarySearch(Function, left, right) << std::endl;

    return EXIT_SUCCESS;
}