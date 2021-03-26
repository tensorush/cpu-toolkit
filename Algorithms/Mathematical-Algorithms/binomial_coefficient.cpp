/*
    Binomial Coefficient
    --------------------
    Time: O(k)
    Space: O(1)
*/
#include <iostream>

size_t BinomialCoefficient(size_t& n, size_t& k) {
	size_t coef = 1;
    if (k > n - k) k = n - k;
	for (size_t i = 1; i <= k; ++i) {
		coef = coef * (n - k + i) / i;
    }
	return coef;
}

int main() {
    size_t n, k;
    std::cin >> n >> k;
    std::cout << BinomialCoefficient(n, k) << std::endl;

    return 0;
}