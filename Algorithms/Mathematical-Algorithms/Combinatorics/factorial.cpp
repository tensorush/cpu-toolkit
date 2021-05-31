/*
    Factorial
    -----------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>

unsigned Factorial(const unsigned& n) {
    unsigned factorial = 1;
    if (n == 0 || n == 1) return factorial;
    for (unsigned i = 2; i <= n; ++i) {
        factorial *= i;
    }
	return factorial;
}

int main() {
    unsigned n;
    std::cin >> n;
    std::cout << Factorial(n) << std::endl;

    return EXIT_SUCCESS;
}