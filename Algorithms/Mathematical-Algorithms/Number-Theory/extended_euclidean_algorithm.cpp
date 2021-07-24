/*
    Extended Euclidean Algorithm
    ----------------------------
    Time: O(log(min(a,b)))
    Space: O(1)
*/
#include <iostream>

int ExtendedEuclideanAlgorithm(int a, int b, int& x, int& y) {
    int quotient, temp, x_0 = y = 0, y_0 = x = 1;
    while (b != 0) {
        quotient = a / b;
        temp = b;
        b = a % b;
        a = temp;
        temp = x_0;
        x_0 = x - quotient * x_0;
        x = temp;
        temp = y_0;
        y_0 = y - quotient * y_0;
        y = temp;
    }
    return a;
}

int main() {
    int a, b, x, y;
    std::cin >> a >> b;
    int gcd = ExtendedEuclideanAlgorithm(a, b, x, y);
    std::cout << "a * x + b * y = gcd" << std::endl
        << a << " * " << x << " + " << b << " * " << y << " = " << gcd << std::endl;

    return EXIT_SUCCESS;
}