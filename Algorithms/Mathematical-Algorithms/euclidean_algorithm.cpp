/*
    Euclidean Algorithm
    ----------------------
    Time: O(log(min(a,b)))
    Space: O(1)
*/
#include <iostream>

int EuclideanAlgorithm(const int& a, const int& b) {
    return (b)?(EuclideanAlgorithm(b, a % b)):(a);
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << EuclideanAlgorithm(a, b) << std::endl;

    return 0;
}