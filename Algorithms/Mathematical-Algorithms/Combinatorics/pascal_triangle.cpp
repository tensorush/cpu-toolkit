/*
    Pascal's Triangle
    -----------------
    Time: O(n*k)
    Space: O(1)
*/
#include <iostream>

void PascalTriangle(const unsigned& n) {
    unsigned coef = 1;
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned numSpaces = 1; numSpaces <= n - i; ++numSpaces) {
            std::cout << "  ";
        }
        for (unsigned k = 0; k <= i; ++k) {
            coef = (k == 0 || i == 0)?(1):((coef * (i - k + 1)) / k);
            std::cout << coef << "   ";
        }
        std::cout << std::endl;
    }
}

int main() {
    unsigned n;
    std::cin >> n;
    PascalTriangle(n);

    return 0;
}