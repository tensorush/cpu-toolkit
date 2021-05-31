/*
    Sieve of Atkin
    ----------------
    Time: O(n)
    Space: O(n bits)
*/
#include <iostream>
#include <vector>
#include <cmath>

auto SieveOfAtkin(const int& bound) {
    std::vector<bool> sieve(bound + 1);
    sieve[2] = sieve[3] = sieve[5] = true;
    int n, x, y, mod, squareMultiples, maxPrime = sqrt(bound), wheelBound = bound / 60;
    std::vector<int> modSixty = {1, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 49, 53, 59};
    for (x = 1; x <= maxPrime; ++x) {
        for (y = 1; y <= maxPrime; y += 2) {
            n = 4 * pow(x, 2) + pow(y, 2);
            mod = n % 60;
            if (n <= bound && (mod == 1 || mod == 13 || mod == 17 || mod == 29
                           || mod == 37 || mod == 41 || mod == 49 || mod == 53)) sieve[n] = !sieve[n];
        }
    }
    for (x = 1; x <= maxPrime; x += 2) {
        for (y = 2; y <= maxPrime; y += 2) {
            n = 3 * pow(x, 2) + pow(y, 2);
            mod = n % 60;
            if (n <= bound && (mod == 7 || mod == 19 || mod == 31 || mod == 43)) sieve[n] = !sieve[n];
        }
    }
    for (x = 2; x <= maxPrime; ++x) {
        for (y = x - 1; y > 0; y -= 2) {
            n = 3 * pow(x, 2) - pow(y, 2);
            mod = n % 60;
            if (n <= bound && (mod == 11 || mod == 23 || mod == 47 || mod == 59)) sieve[n] = !sieve[n];
        }
    }
    for (int wheel = 0; wheel <= wheelBound; ++wheel) {
        for (const int& remainder : modSixty) {
            n = 60 * wheelBound + remainder;
            if (n <= maxPrime && sieve[n]) {
                for (int wheel = 0; wheel <= wheelBound; ++wheel) {
                    for (const int& remainder : modSixty) {
                        squareMultiples = pow(n, 2) * (60 * wheelBound + remainder);
                        if (squareMultiples <= bound) sieve[squareMultiples] = false;
                    }
                }
            }
        }
    }
    return std::make_pair(sieve, modSixty);
}

int main() {
    int bound;
    std::cin >> bound;
    auto [sieve, modSixty] = SieveOfAtkin(bound);
    std::cout << 2 << ' ' << 3 << ' ' << 5 << ' ';
    for (int i = 1; i < 16; ++i) {
        if (modSixty[i] <= bound) std::cout << modSixty[i] << ' ';
    }
    int n, wheelBound = bound / 60;
    for (int wheel = 1; wheel <= wheelBound; ++wheel) {
        for (const int& remainder : modSixty) {
            n = 60 * wheel + remainder;
            if (n <= bound && sieve[n]) std::cout << n << ' ';
        }
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}