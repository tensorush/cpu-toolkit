/*
    Karatsuba Algorithm
    -------------------
    Time: O(n^1.585)
    Space: O(1)
*/
#include <algorithm>
#include <iostream>
#include <cmath>

template <typename T>
T KaratsubaAlgorithm(const T& x, const T& y) {
    if (x < 10 || y < 10)
        return x * y;
    T n = std::min(std::log10(x), std::log10(y)), p = std::pow(10, n / 2),
        a = x / p, b = x % p,
        c = y / p, d = y % p,
        u = KaratsubaAlgorithm(a, c),
        v = KaratsubaAlgorithm(b, d),
        w = KaratsubaAlgorithm(a + b, c + d);
    return u * std::pow(10, n) + (w - u - v) * std::pow(10, n / 2) + v;
}

int main() {
    long long x, y;
    std::cin >> x >> y;
    std::cout << KaratsubaAlgorithm(x, y);

    return EXIT_SUCCESS;
}