/*
    Fermat's Primality Test
    -----------------------------
    Time: O(log(n)*numIterations)
    Space: O(1)
*/
#include <iostream>
#include <chrono>
#include <random>
#include <vector>

unsigned EuclideanAlgorithm(unsigned a, unsigned b) {
    while (a > 0) {
        b %= a;
        std::swap(a, b);
    }
    return b;
}

unsigned FermatLittleTheorem(unsigned a, const unsigned& p) {
    unsigned n = p - 1, mod = 1;
    a %= p;
    while (n) {
        if (n % 2 == 1) mod = (mod * a) % p;
        a = (a * a) % p;
        n /= 2;
    }
    return mod;
}

bool FermatPrimalityTest(const unsigned& n, unsigned numIterations) {
    if (n < 2 || n == 4) return false;
    if (n < 4) return true;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 randomInteger(seed);
    while (--numIterations) {
        unsigned a = 2 + randomInteger() % (n - 4);
        if (EuclideanAlgorithm(a, n) != 1 || FermatLittleTheorem(a, n) != 1) return false;
    }
    return true;
}

int main() {
    unsigned n, numIterations;
    std::cin >> n >> numIterations;
    std::cout << std::boolalpha << FermatPrimalityTest(n, numIterations) << std::endl;

    return EXIT_SUCCESS;
}