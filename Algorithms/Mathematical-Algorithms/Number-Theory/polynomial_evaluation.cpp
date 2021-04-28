/*
    Polynomial Evaluation
    ---------------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>
#include <vector>

int PolynomialEvaluation(const std::vector<int>& polynom, const int& value) {
    int result = polynom.back();
    for (int i = polynom.size() - 2; i >= 0; --i) {
        result = polynom[i] + value * result;
    }
    return result;
}

int main() {
    size_t n;
    int value;
    std::cin >> n >> value;
    std::vector<int> polynom(n + 1);
    for (int& coefficient : polynom) {
        std::cin >> coefficient;
    }
    std::cout << PolynomialEvaluation(polynom, value) << std::endl;

    return 0;
}