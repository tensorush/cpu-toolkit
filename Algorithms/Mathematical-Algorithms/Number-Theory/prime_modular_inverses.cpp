/*
    Prime Modular Inverses
    ----------------------
    Time: O(m)
    Space: O(m)
*/
#include <iostream>
#include <vector>

auto PrimeModularInverses(const size_t& m) {
	std::vector<size_t> inverses(m);
	inverses[1] = 1;
    for (size_t i = 2; i < m; ++i) {
        inverses[i] = m - (m / i) * inverses[m % i] % m;
    }
    return inverses;
}

int main() {
    size_t m;
    std::cin >> m;
    auto inverses = PrimeModularInverses(m);
    for (size_t inv : inverses) {
        std::cout << inv << ' ';
    }
    std::cout << std::endl;

    return 0;
}