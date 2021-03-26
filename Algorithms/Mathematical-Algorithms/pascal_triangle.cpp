/*
    Pascal's Triangle
    -----------------
    Time: O(n*k)
    Space: O(1)
*/
#include <iostream>

void PascalTriangle(const size_t& n) {
    size_t coef = 1;
    for (size_t i = 0; i < n; ++i) {
        for (size_t numSpaces = 1; numSpaces <= n - i; ++numSpaces) {
            std::cout << "  ";
        }
        for (size_t k = 0; k <= i; ++k) {
            (k == 0 || i == 0)?(coef = 1):(coef = coef * (i - k + 1) / k);
            std::cout << coef << "   ";
        }
        std::cout << std::endl;
    }
}

int main() {
    size_t n;
    std::cin >> n;
    PascalTriangle(n);

    return 0;
}