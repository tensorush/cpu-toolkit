/*
    Fibonacci Number
    ----------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>

size_t FibonacciNumber(const size_t& n) {
    size_t prev = 0, cur = 1, new_cur;
    if (n <= 1) return n;
    for (size_t i = 2; i <= n; ++i) {
        new_cur = prev + cur;
        prev = cur;
        cur = new_cur;
    }
    return cur;
}

int main() {
    size_t n;
    std::cin >> n;
    std::cout << FibonacciNumber(n) << std::endl;

    return 0;
}