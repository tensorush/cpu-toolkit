/*
    Euclidean Algorithm
    ----------------------
    Time: O(log(min(a,b)))
    Space: O(1)
*/
#include <iostream>

int EuclideanAlgorithm(int a, int b) {
    while (b > 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << EuclideanAlgorithm(a, b) << std::endl;

    return 0;
}