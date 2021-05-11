/*
    Fibonacci Number
    ---------------------------------------------------------------
    | Implicit Formula | Matrix Exponentiation | Explicit Formula |
    ---------------------------------------------------------------
    | Time: O(n)       |       O(log(n))       |       O(1)       |
    | Space: O(1)      |          O(1)         |       O(1)       |
    ---------------------------------------------------------------
*/
#include <iostream>
#include <cmath>

enum Algorithm {ImplicitFormula, MatrixExponentiation, ExplicitFormula};

unsigned FibonacciNumber(unsigned n, const Algorithm& algorithm = MatrixExponentiation) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    if (algorithm == MatrixExponentiation) {
        // TODO
    } else if (algorithm == ImplicitFormula) {
        unsigned prev = 0, cur = 1, next;
        while (--n) {
            next = prev + cur;
            prev = cur;
            cur = next;
        }
        return cur;
    } else if (algorithm == ExplicitFormula) {
        double goldenRatio = (1 + sqrt(5)) / 2;
        return round(pow(goldenRatio, n) / sqrt(5));
    }
}

int main() {
    unsigned n;
    std::cin >> n;
    std::cout << FibonacciNumber(n) << std::endl;

    return 0;
}