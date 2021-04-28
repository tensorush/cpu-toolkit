/*
    Linear Sieve Algorithm
    ----------------------
    Time: O(n)
    Space: O(n)
*/
#include <iostream>
#include <vector>

auto LinearSieveAlgorithm(const size_t& n) {
    size_t numPrimes;
    std::vector<size_t> primes, primeDivs(n + 1);
    for (size_t i = 2; i <= n; ++i) {
        if (primeDivs[i] == 0) {
            primeDivs[i] = i;
            primes.emplace_back(i);
        }
        numPrimes = primes.size();
        for (size_t j = 0, x = i * 2; j < numPrimes && primes[j] <= primeDivs[i] && x <= n; x = i * primes[++j]) {
            primeDivs[x] = primes[j];
        }
    }
    return primeDivs;
}

int main() {
    size_t n; // less than 10^7
    std::cin >> n;
    auto smallestPrimeDivisors = LinearSieveAlgorithm(n);
    for (size_t i = 2; i <= n; ++i) {
        std::cout << i << " | " << smallestPrimeDivisors[i] << std::endl;
    }

    return 0;
}