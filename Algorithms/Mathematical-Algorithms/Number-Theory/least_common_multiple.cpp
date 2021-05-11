/*
    Least Common Multiple
    ---------------------
    Time: O(log(a*b))
    Space: O(1)
*/
#include <iostream>

int GreatestCommonDivisor(int a, int b) {
    while (b > 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int LeastCommonMultiple(const int& a, const int& b) {
    return a / GreatestCommonDivisor(a, b) * b;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << LeastCommonMultiple(a, b) << std::endl;

    return 0;
}