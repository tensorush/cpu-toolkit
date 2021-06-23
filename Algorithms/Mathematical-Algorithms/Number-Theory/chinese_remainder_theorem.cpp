/*
    Chinese Remainder Theorem
    ------------------------------------------
    | Garner's Algorithm | Gauss's Algorithm |
    ------------------------------------------
    | Time: O(n^2)       | O(n log(coprime)) |
    | Space: O(n)        |       O(1)        |
    ------------------------------------------
*/
#include <iostream>
#include <vector>

enum class Algorithm
{
    Gauss = 0,
    Garner = 1
};

int ModularInverse(int a, int m)
{
    // Extended Euclidean Algorithm
    int temp, quotient, x = 0, y = 1, mod = m;
    if (m == 1)
        return x;
    while (a > 1)
    {
        temp = m;
        quotient = a / m;
        m = a % m;
        a = temp;
        temp = x;
        x = y - quotient * x;
        y = temp;
    }
    return (y < 0) ? (y + mod) : (y);
}

auto ChineseRemainderTheorem(const Algorithm &algorithm, const std::vector<int> &coprimes, const std::vector<int> &remainders)
{
    size_t n = coprimes.size();
    int x = 0, coprimesProduct = 1;
    for (const int &coprime : coprimes)
    {
        coprimesProduct *= coprime;
    }
    switch (algorithm)
    {
    case Algorithm::Gauss:
        int y_i;
        for (size_t i = 0; i < n; ++i)
        {
            y_i = coprimesProduct / coprimes[i];
            x += remainders[i] * ModularInverse(y_i, coprimes[i]) * y_i;
        }
        x %= coprimesProduct;
        break;
    case Algorithm::Garner:
        int x_i;
        std::vector<int> coef(n);
        for (size_t i = 0; i < n; ++i)
        {
            coef[i] = remainders[i];
            for (int j = 0; j < i; ++j)
            {
                coef[i] = (ModularInverse(coprimes[i], coprimes[j]) * (coef[i] - coef[j])) % coprimes[i];
                if (coef[i] < 0)
                    coef[i] += coprimes[i];
            }
            x_i = coef[i];
            for (int j = 0; j < i; ++j)
            {
                x_i *= coprimes[j];
            }
            x += x_i;
        }
    }
    return std::make_pair(x, coprimesProduct);
}

int main()
{
    unsigned algorithm, n;
    std::cin >> algorithm >> n;
    std::vector<int> coprimes(n);
    for (int &coprime : coprimes)
    {
        std::cin >> coprime;
    }
    std::vector<int> remainders(n);
    for (int &remainder : remainders)
    {
        std::cin >> remainder;
    }
    auto [x, coprimesProduct] = ChineseRemainderTheorem(static_cast<Algorithm>(algorithm), coprimes, remainders);
    std::cout << x << " mod " << coprimesProduct << std::endl;

    return EXIT_SUCCESS;
}