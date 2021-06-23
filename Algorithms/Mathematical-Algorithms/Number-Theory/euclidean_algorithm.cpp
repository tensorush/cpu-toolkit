/*
    Euclidean Algorithm
    ----------------------
    Time: O(log(min(a,b)))
    Space: O(1)
*/
#include <iostream>

int EuclideanAlgorithm(int a, int b)
{
    while (a > 0)
    {
        b %= a;
        std::swap(a, b);
    }
    return b;
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << EuclideanAlgorithm(a, b) << std::endl;

    return EXIT_SUCCESS;
}