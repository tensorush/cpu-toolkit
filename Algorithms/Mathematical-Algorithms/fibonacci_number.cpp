/*
    Fibonacci Number
    ----------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>

size_t FibonacciNumber(const size_t& n) {
    size_t prev = 0, cur = 1, next;
    if (n < 2) return n;
    for (size_t i = 2; i <= n; ++i) {
        next = prev + cur;
        prev = cur;
        cur = next;
    }
    return cur;
}

int main() {
    size_t n;
    std::cin >> n;
    std::cout << FibonacciNumber(n) << std::endl;

    return 0;
}