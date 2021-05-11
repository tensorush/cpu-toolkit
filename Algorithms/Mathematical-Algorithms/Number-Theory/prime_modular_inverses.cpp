/*
    Prime Modular Inverses
    ----------------------
    Time: O(m)
    Space: O(m)
*/
#include <iostream>
#include <vector>

auto PrimeModularInverses(const unsigned& prime) {
	std::vector<unsigned> inverses(prime);
	inverses[1] = 1;
    for (unsigned i = 2; i < prime; ++i) {
        inverses[i] = prime - (prime / i) * inverses[prime % i] % prime;
    }
    return inverses;
}

int main() {
    unsigned prime;
    std::cin >> prime;
    auto inverses = PrimeModularInverses(prime);
    for (const unsigned& inverse : inverses) {
        std::cout << inverse << ' ';
    }
    std::cout << std::endl;

    return 0;
}