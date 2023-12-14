/*
    Miller-Rabin Primality Test
    -----------------------------
    Time: O(log(n)*numIterations)
    Space: O(1)
*/
#include <iostream>
#include <chrono>
#include <random>
#include <vector>

unsigned ModularExponentiation(unsigned a, unsigned power, const unsigned& p) {
    unsigned mod = 1;
    a %= p;
    while (power) {
        if (power % 2 == 1)
            mod = (mod * a) % p;
        a = (a * a) % p;
        power /= 2;
    }
    return mod;
}

bool MillerRabinPrimalityTest(const unsigned& n, unsigned numIterations) {
    if (n <= 1 || n == 4)
        return false;
    if (n == 2 || n == 3)
        return true;
    unsigned d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    bool isPrime;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 randomInteger(seed);
    while (--numIterations) {
        isPrime = false;
        unsigned a = 2 + randomInteger() % (n - 4);
        unsigned mod = ModularExponentiation(a, d, n);
        if (mod == 1 || mod == n - 1)
            continue;
        while (d != n - 1) {
            mod = (mod * mod) % n;
            d *= 2;
            if (mod == 1)
                return false;
            if (mod == n - 1) {
                isPrime = true;
                break;
            }
        }
        if (isPrime == false)
            return false;
    }
    return true;
}

int main() {
    unsigned number, numIterations;
    std::cin >> number >> numIterations;
    std::cout << std::boolalpha << MillerRabinPrimalityTest(number, numIterations) << std::endl;

    return EXIT_SUCCESS;
}