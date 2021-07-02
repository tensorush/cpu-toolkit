/*
    Horner's Method
    ---------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>
#include <vector>

int HornerMethod(const std::vector<int>& polynomial, const int& value) {
    int result = polynomial.back();
    for (int i = polynomial.size() - 2; i >= 0; --i) {
        result = polynomial[i] + value * result;
    }
    return result;
}

int main() {
    unsigned n;
    int value;
    std::cin >> n >> value;
    std::vector<int> polynomial(n + 1);
    for (int& coefficient : polynomial) {
        std::cin >> coefficient;
    }
    std::cout << HornerMethod(polynomial, value) << std::endl;

    return EXIT_SUCCESS;
}