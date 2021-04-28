/*
    Catalan Number
    --------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>

unsigned CatalanNumber(const unsigned& n) {
    unsigned cat = 1;
	for (unsigned i = 0; i < n; ++i) {
		cat *= 4 * i + 2;
        cat /= i + 2;
    }
	return cat;
}

int main() {
    unsigned n;
    std::cin >> n;
    std::cout << CatalanNumber(n) << std::endl;

    return 0;
}