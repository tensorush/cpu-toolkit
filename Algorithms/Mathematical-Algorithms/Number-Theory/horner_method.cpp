/*
    Horner's Method
    ---------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>
#include <vector>

int HornerMethod(const std::vector<int>& polynom, const int& value) {
    int result = polynom.back();
    for (int i = polynom.size() - 2; i >= 0; --i) {
        result = polynom[i] + value * result;
    }
    return result;
}

int main() {
    unsigned n;
    int value;
    std::cin >> n >> value;
    std::vector<int> polynom(n + 1);
    for (int& coefficient : polynom) {
        std::cin >> coefficient;
    }
    std::cout << HornerMethod(polynom, value) << std::endl;

    return 0;
}