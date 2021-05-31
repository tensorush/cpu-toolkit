/*
    Binomial Coefficient
    --------------------
    Time: O(k)
    Space: O(1)
*/
#include <iostream>

unsigned BinomialCoefficient(const unsigned& n, unsigned& k) {
	unsigned coef = 1;
    if (k > n - k) k = n - k;
	for (unsigned i = 1; i <= k; ++i) {
		coef *= n - k + i;
        coef /= i;
    }
	return coef;
}

int main() {
    unsigned n, k;
    std::cin >> n >> k;
    std::cout << BinomialCoefficient(n, k) << std::endl;

    return EXIT_SUCCESS;
}