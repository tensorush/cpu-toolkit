/*
    Linear Sieve Algorithm
    ----------------------
    Time: O(n)
    Space: O(n)
*/
#include <iostream>
#include <vector>

auto LinearSieveAlgorithm(const unsigned& n) {
    unsigned numPrimes;
    std::vector<unsigned> primes, primeDivs(n + 1);
    for (unsigned i = 2; i <= n; ++i) {
        if (primeDivs[i] == 0) {
            primeDivs[i] = i;
            primes.emplace_back(i);
        }
        numPrimes = primes.size();
        for (unsigned j = 0, x = i * 2; j < numPrimes && primes[j] <= primeDivs[i] && x <= n; ++j, x = i * primes[j]) {
            primeDivs[x] = primes[j];
        }
    }
    return primeDivs;
}

int main() {
    unsigned n;
    std::cin >> n;
    auto smallestPrimeDivisors = LinearSieveAlgorithm(n);
    for (unsigned i = 2; i <= n; ++i) {
        std::cout << i << " | " << smallestPrimeDivisors[i] << std::endl;
    }

    return EXIT_SUCCESS;
}