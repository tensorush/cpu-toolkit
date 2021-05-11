/*
    Fermat's Primality Test
    -----------------------------
    Time: O(log(n)*numIterations)
    Space: O(1)
*/
#include <iostream>
#include <vector>
#include <ctime>

unsigned EuclideanAlgorithm(unsigned a, unsigned b) {
    while (b > 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
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
    srand(time(0));
    while (--numIterations) {
        unsigned a = 2 + rand() % (n - 4);
        if (EuclideanAlgorithm(a, n) != 1) return false;
        if (FermatLittleTheorem(a, n) != 1) return false;
    }
    return true;
}

int main() {
    unsigned n, numIterations;
    std::cin >> n >> numIterations;
    std::cout << std::boolalpha << FermatPrimalityTest(n, numIterations) << std::endl;

    return 0;
}