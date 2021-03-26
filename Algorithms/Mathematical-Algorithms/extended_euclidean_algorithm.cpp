/*
    Extended Euclidean Algorithm
    ----------------------------
    Time: O(log(min(a,b)))
    Space: O(1)
*/
#include <iostream>

auto ExtendedEuclideanAlgorithm(int a, int b, int* x, int* y) {
    if (b == 0) {
		*x = 1;
        *y = 0;
    	return a;
	}
	int x_1, y_1;
	int gcd = ExtendedEuclideanAlgorithm(b, a % b, &x_1, &y_1);
	*x = y_1;
    *y = x_1 - (a / b) * y_1;
	return gcd;
}

int main() {
    int a, b, x, y;
    std::cin >> a >> b;
    int gcd = ExtendedEuclideanAlgorithm(a, b, &x, &y);
    std::cout << "a * x + b * y = gcd" <<
    std::endl << a << " * " << x << " + " << b << " * " << y << " = " << gcd << std::endl;

    return 0;
}