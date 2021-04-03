/*
    Polynomial Evaluation
    ---------------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>
#include <vector>

int PolynomialEvaluation(const std::vector<int>& c, const int& x) {
    int result = c.back();
    for (int i = c.size() - 1; i > 0; --i) {
        result = c[i - 1] + x * result;
    }
    return result;
}

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> c[i];
    }
    std::cout << PolynomialEvaluation(c, x);

    return 0;
}