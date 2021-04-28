/*
    Euler's Totient (Phi) Function
    ------------------------------
    Time: O(sqrt(n))
    Space: O(1)
*/
#include <iostream>
#include <vector>

size_t TotientFunction(size_t n) {
	size_t numCoPrimes = n;
	for (size_t i = 2; i * i <= n; ++i)
		if (n % i == 0) {
			while (n % i == 0) n /= i;
			numCoPrimes -= numCoPrimes / i;
		}
	if (n > 1) numCoPrimes -= numCoPrimes / n;
	return numCoPrimes;
}

int main() {
    size_t n;
    std::cin >> n;
    std::cout << TotientFunction(n) << std::endl;

    return 0;
}