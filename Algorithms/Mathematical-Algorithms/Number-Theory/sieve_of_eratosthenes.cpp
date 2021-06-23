/*
    Sieve of Eratosthenes
    ---------------------
    Time: O(n log(log(n))
    Space: O(n bits)
*/
#include <iostream>
#include <vector>
#include <cmath>

auto SieveOfEratosthenes(const unsigned &bound)
{
    std::vector<bool> sieve(bound + 1, true);
    sieve[0] = sieve[1] = false;
    unsigned maxPrime = std::sqrt(bound);
    for (unsigned p = 2; p <= maxPrime; ++p)
    {
        if (sieve[p] == true)
        {
            for (unsigned i = p * p; i <= bound; i += p)
            {
                sieve[i] = false;
            }
        }
    }
    return sieve;
}

int main()
{
    unsigned bound;
    std::cin >> bound;
    auto sieve = SieveOfEratosthenes(bound);
    for (unsigned i = 2; i <= bound; ++i)
    {
        if (sieve[i])
            std::cout << i << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}