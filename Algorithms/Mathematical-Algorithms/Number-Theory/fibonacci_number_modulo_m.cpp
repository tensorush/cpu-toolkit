/*
    Fibonacci Number Modulo M
    -------------------------
    Time: O(n)
    Space: O(m)
*/
#include <iostream>
#include <vector>

unsigned FibonacciNumberModuloM(unsigned n, unsigned m) {
    std::vector<unsigned> fib(6 * m + 2);
    fib[1] = fib[2] = 1;
    unsigned i;
    for (i = 3; i <= n && (fib[i - 2] != 0 || fib[i - 1] != 1); ++i) {
        fib[i] = (fib[i - 2] + fib[i - 1]) % m;
    }
    unsigned pisanoPeriod = i - 2;
    return (n < i)?(fib[n]):(fib[n % pisanoPeriod]);
}

int main() {
    unsigned n, m;
    std::cin >> n >> m;
    std::cout << FibonacciNumberModuloM(n, m) << std::endl;

    return 0;
}