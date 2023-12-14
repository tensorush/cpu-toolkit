/*
    Fibonacci Number Modulo M
    -------------------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>

unsigned FibonacciNumberModuloM(const unsigned& n, const unsigned& m) {
    unsigned prev = 0, cur = 1, next = 1, pisanoPeriod = 0;
    if (n == 0)
        return prev;
    if (n == 1)
        return cur;
    do {
        next = (prev + cur) % m;
        prev = cur;
        cur = next;
        ++pisanoPeriod;
    } while (prev != 0 || cur != 1);
    prev = 0, cur = 1, next = 1;
    for (unsigned remainder = n % pisanoPeriod; remainder > 1; --remainder) {
        next = (prev + cur) % m;
        prev = cur;
        cur = next;
    }
    return cur;
}

int main() {
    unsigned n, m;
    std::cin >> n >> m;
    std::cout << FibonacciNumberModuloM(n, m) << std::endl;

    return EXIT_SUCCESS;
}