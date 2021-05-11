/*
    Miller-Rabin Primality Test
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

unsigned modularExponentiation(unsigned a, unsigned power, const unsigned& p) {
    unsigned mod = 1;
    a %= p;
    while (power) {
        if (power % 2 == 1) mod = (mod * a) % p;
        a = (a * a) % p;
        power /= 2;
    }
    return mod;
}

bool MillerRabinPrimalityTest(const unsigned& n, unsigned numIterations) {
    if (n < 2 || n == 4)  return false;
    if (n < 4) return true;
    unsigned d = n - 1;
    while (d % 2 == 0) d /= 2;
    bool isPrime;
    srand(time(0));
    while (--numIterations) {
        isPrime = false;
        unsigned a = 2 + rand() % (n - 4);
        unsigned mod = modularExponentiation(a, d, n);
        if (mod == 1 || mod == n - 1) continue ;
        while (d != n - 1) {
            mod = (mod * mod) % n;
            d *= 2;
            if (mod == 1) return false;
            if (mod == n - 1) {
                isPrime = true;
                break;
            }
        }
        if (!isPrime) return false;
    }
    return true;
}

int main() {
    unsigned number, numIterations;
    std::cin >> number >> numIterations;
    std::cout << std::boolalpha << MillerRabinPrimalityTest(number, numIterations) << std::endl;

    return 0;
}