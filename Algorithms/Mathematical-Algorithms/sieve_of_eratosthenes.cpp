/*
    Sieve of Eratosthenes
    ---------------------
    Time: O(n log(log(n))
    Space: O(n bytes)
*/
#include <iostream>
#include <vector>

auto SieveOfEratosthenes(const size_t& n) {
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (size_t p = 2; p * p <= n; ++p) {
        if (isPrime[p] == true) {
            for (size_t i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
    return isPrime;
}

int main() {
    size_t n;
    std::cin >> n;
    auto isPrime = SieveOfEratosthenes(n);
    for (size_t i = 2; i <= n; ++i) {
        if (isPrime[i]) std::cout << i << std::endl;
    }

    return 0;
}