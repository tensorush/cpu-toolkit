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
#include <vector>
#include <cmath>

enum class Algorithm {ImplicitFormula = 0, MatrixExponentiation = 1, ExplicitFormula = 2};

unsigned FibonacciNumber(const Algorithm& algorithm, unsigned n) {
    unsigned prev = 0, cur = 1, next = 1;
    std::vector<std::vector<unsigned>> dotProducts, recurrence = {{1, 1}, {1, 0}}, fibonacci = {{1, 1}, {1, 1}};
    if (n == 0) return prev;
    if (n == 1) return cur;
    if (n == 2) return next;
    switch (algorithm) {
        case Algorithm::MatrixExponentiation:
            n -= 3;
            while (n) {
                if (n % 2 == 1) {
                    dotProducts = {{0, 0}, {0, 0}};
                    for (unsigned i = 0; i < 2; ++i) {
                        for (unsigned j = 0; j < 2; ++j) {
                            for (unsigned k = 0; k < 2; ++k) {
                                dotProducts[i][k] += fibonacci[i][j] * recurrence[j][k];
                            }
                        }
                    }
                    fibonacci = dotProducts;
                }
                dotProducts = {{0, 0}, {0, 0}};
                for (unsigned i = 0; i < 2; ++i) {
                    for (unsigned j = 0; j < 2; ++j) {
                        for (unsigned k = 0; k < 2; ++k) {
                            dotProducts[i][k] += recurrence[i][j] * recurrence[j][k];
                        }
                    }
                }
                recurrence = dotProducts;
                n /= 2;
            }
            cur = fibonacci[0][0] + fibonacci[0][1];
            break;
        case Algorithm::ImplicitFormula:
            while (--n) {
                next = prev + cur;
                prev = cur;
                cur = next;
            }
            break;
        case Algorithm::ExplicitFormula:
            double goldenRatio = (1 + std::sqrt(5)) / 2;
            cur = std::round(std::pow(goldenRatio, n) / std::sqrt(5));
    }
    return cur;
}

int main() {
    unsigned algorithm, n;
    std::cin >> algorithm >> n;
    std::cout << FibonacciNumber(static_cast<Algorithm>(algorithm), n) << std::endl;

    return EXIT_SUCCESS;
}