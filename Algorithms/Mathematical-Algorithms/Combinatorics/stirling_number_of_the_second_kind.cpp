/*
    Stirling Number Of The Second Kind
    ----------------------------------
    Time: O(k)
    Space: O(1)
*/
#include <iostream>
#include <cmath>

unsigned Factorial(const unsigned& n) {
    unsigned factorial = 1;
    if (n == 0 || n == 1) return factorial;
    for (unsigned i = 2; i <= n; ++i) {
        factorial *= i;
    }
	return factorial;
}

unsigned StirlingNumberOfTheSecondKind(const unsigned& n, const unsigned& k) {
    double summand, stirling = 0;
	for (unsigned i = 0; i <= k; ++i) {
		summand = pow(k - i, n) / Factorial(k - i) / Factorial(i);
        if (i % 2 == 1) summand *= -1;
        stirling += summand;
    }
	return round(stirling);
}

int main() {
    unsigned n, k;
    std::cin >> n >> k;
    std::cout << StirlingNumberOfTheSecondKind(n, k) << std::endl;

    return 0;
}