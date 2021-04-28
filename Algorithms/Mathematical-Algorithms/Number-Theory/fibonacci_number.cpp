/*
    Fibonacci Number
    ----------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>

size_t FibonacciNumber(size_t n) {
    size_t prev = 0, cur = 1, next;
    while (--n) {
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