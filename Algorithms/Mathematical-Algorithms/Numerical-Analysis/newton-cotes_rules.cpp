/*
    Newton-Cotes Rules
    ----------------------------------------------------------------------------------
    | Trapezoidal Rule | Simpson's First Rule | Simpson's Second Rule | Boole's Rule |
    ----------------------------------------------------------------------------------
    | Time: O(n)       |          O(n)        |          O(n)         |      O(n)    |
    | Space: O(1)      |          O(1)        |          O(1)         |      O(1)    |
    ----------------------------------------------------------------------------------
*/
#include <functional>
#include <iostream>
#include <cassert>
#include <cmath>

enum class Rule {Trapezoidal = 0, SimpsonFirst = 1, SimpsonSecond = 2, Boole = 3};

double NewtonCotesRules(std::function<double (const double&)> Function, const Rule& rule, const double& a, const double& b, const unsigned& n) {
    double integral = 0, step = (b - a) / n;
    switch (rule) {
        case Rule::Trapezoidal:
            integral += (Function(a) + Function(b)) / 2;
            for (unsigned i = 1; i < n; ++i) {
                integral += Function(a + step * i);
            }
            integral *= step;
            break;
        case Rule::SimpsonFirst:
            integral += Function(a) + Function(b);
            for (unsigned i = 1; i < n; ++i) {
                integral += Function(a + step * i) * ((i % 2 == 0)?(2):(4));
            }
            integral *= step / 3;
            break;
        case Rule::SimpsonSecond:
            integral += Function(a) + Function(b);
            for (unsigned i = 1; i < n; ++i) {
                integral += Function(a + step * i) * ((i % 3 == 0)?(2):(3));
            }
            integral *= 3 * step / 8;
            break;
        case Rule::Boole:
            integral += 7 * (Function(a) + Function(b));
            for (unsigned i = 1; i < n; i += 2) {
                integral += 32 * Function(a + step * i);
            }
            for (unsigned i = 2; i < n; i += 4) {
                integral += 12 * Function(a + step * i);
            }
            for (unsigned i = 4; i < n; i += 4) {
                integral += 14 * Function(a + step * i);
            }
            integral *= 2 * step / 45;
    }
    return integral;
}

int main() {
    double start, end;
    unsigned rule, numSplits;
    std::cin >> rule >> start >> end >> numSplits;
    assert(numSplits % 2 == 0, "Number of splits should be divisible by two");
    auto Function = [](const double& x) -> double { return std::cosh(x); };
    std::cout << NewtonCotesRules(Function, static_cast<Rule>(rule), start, end, numSplits) << std::endl;

    return EXIT_SUCCESS;
}