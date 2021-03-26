/*
    Least Common Multiple
    ---------------------
    Time: O(log(a*b))
    Space: O(1)
*/
#include <iostream>

int GreatestCommonDivisor(const int& a, const int& b) {
    return (b)?(GreatestCommonDivisor(b, a % b)):(a);
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