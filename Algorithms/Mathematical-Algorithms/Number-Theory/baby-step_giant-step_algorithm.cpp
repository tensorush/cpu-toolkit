/*
    Baby-Step Giant-Step Algorithm
    ------------------------------
    Time: O(sqrt(m))
    Space: O(sqrt(m))
*/
#include <unordered_map>
#include <iostream>
#include <cmath>

int BabyStepGiantStepAlgorithm(const unsigned &a, const unsigned &b, const unsigned &m)
{
    unsigned n = std::sqrt(m) + 1, NthPowerOfA = 1;
    for (unsigned i = 0; i < n; ++i)
    {
        NthPowerOfA = (NthPowerOfA * a) % m;
    }
    std::unordered_map<unsigned, unsigned> values;
    for (unsigned i = 1, cur = NthPowerOfA; i <= n; ++i)
    {
        if (!values[cur])
            values[cur] = i;
        cur = (cur * NthPowerOfA) % m;
    }
    int power = -1;
    for (unsigned i = 0, cur = b; i <= n; ++i)
    {
        if (values[cur])
        {
            power = values[cur] * n - i;
            if (power < m)
                break;
        }
        cur = (cur * a) % m;
    }
    return power;
}

int main()
{
    unsigned a, b, m;
    std::cin >> a >> b >> m;
    std::cout << BabyStepGiantStepAlgorithm(a, b, m) << std::endl;

    return EXIT_SUCCESS;
}