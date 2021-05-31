/*
    Catalan Number
    --------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>

unsigned CatalanNumber(const unsigned& n) {
    unsigned catalan = 1;
	for (unsigned i = 0; i < n; ++i) {
		catalan *= 4 * i + 2;
        catalan /= i + 2;
    }
	return catalan;
}

int main() {
    unsigned n;
    std::cin >> n;
    std::cout << CatalanNumber(n) << std::endl;

    return EXIT_SUCCESS;
}