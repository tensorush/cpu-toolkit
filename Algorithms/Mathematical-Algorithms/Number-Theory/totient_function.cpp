/*
    Euler's Totient Function
    ------------------------
    Time: O(sqrt(n))
    Space: O(1)
*/
#include <iostream>
#include <vector>

unsigned TotientFunction(unsigned n)
{
    unsigned numCoprimes = n;
    for (unsigned i = 2; i * i <= n; ++i)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            numCoprimes -= numCoprimes / i;
        }
    if (n > 1)
        numCoprimes -= numCoprimes / n;
    return numCoprimes;
}

int main()
{
    unsigned n;
    std::cin >> n;
    std::cout << TotientFunction(n) << std::endl;

    return EXIT_SUCCESS;
}