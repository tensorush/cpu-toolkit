/*
    Catalan Number
    --------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>

size_t CatalanNumber(size_t& n) {
    size_t k = n;
	n *= 2;
    size_t coef = 1;
	for (size_t i = 1; i <= k; ++i) {
		coef = coef * (n - k + i) / i;
    }
	return coef / (k + 1);
}

int main() {
    size_t n;
    std::cin >> n;
    std::cout << CatalanNumber(n) << std::endl;

    return 0;
}