/*
    Fibonacci Number Modulo M
    -------------------------
    Time: O(n)
    Space: O(m)
*/
#include <iostream>
#include <vector>

size_t FibonacciNumberModuloM(size_t n, size_t m) {
    std::vector<size_t> fib(6 * m + 2);
    fib[1] = fib[2] = 1;
    size_t i;
    for (i = 3; i <= n && (fib[i - 2] != 0 || fib[i - 1] != 1); ++i) {
        fib[i] = (fib[i - 2] + fib[i - 1]) % m;
    }
    size_t pisanoPeriod = i - 2;
    return (n < i)?(fib[n]):(fib[n % pisanoPeriod]);
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    std::cout << FibonacciNumberModuloM(n, m) << std::endl;

    return 0;
}