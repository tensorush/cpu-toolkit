/*
    Bignum Arithmetic
    -----------------
*/
#include <iostream>
#include <string>

struct BigInt
{
    static const long long BASE = 1e9;
    static const long long SIZE = 10;
    long long digits[SIZE];
    BigInt()
    {
        for (int i = 0; i < SIZE; ++i)
        {
            digits[i] = 0;
        }
    }
    BigInt(long long x)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            digits[i] = 0;
        }
        int next = 0;
        while (x)
        {
            digits[next++] = x % BASE;
            x /= BASE;
        }
    }
    BigInt(const BigInt &other)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            digits[i] = other.digits[i];
        }
    }
    BigInt &operator=(const BigInt &other)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            digits[i] = other.digits[i];
        }
        return *this;
    }
    void operator+=(const BigInt &other)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            digits[i] += other.digits[i];
        }
        for (int i = 0; i < SIZE - 1; ++i)
        {
            if (digits[i] >= BASE)
            {
                digits[i] -= BASE;
                ++digits[i + 1];
            }
        }
    }
    BigInt operator+(const BigInt &other)
    {
        BigInt n(*this);
        n += other;
        return n;
    }
    BigInt &operator++()
    {
        *this += 1;
        return *this;
    }
    void operator-=(const BigInt &other)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            digits[i] -= other.digits[i];
        }
        for (int i = 0; i < SIZE - 1; ++i)
        {
            if (digits[i] < 0)
            {
                digits[i] += BASE;
                --digits[i + 1];
            }
        }
    }
    BigInt operator-(const BigInt &other)
    {
        BigInt n(*this);
        n -= other;
        return n;
    }
    BigInt &operator--()
    {
        *this -= 1;
        return *this;
    }
    void operator*=(const BigInt &other)
    {
        *this = *this * other;
    }
    BigInt operator*(const BigInt &other)
    {
        BigInt result;
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE - i; ++j)
            {
                result.digits[i + j] += digits[i] * other.digits[j];
            }
        }
        for (int i = 0; i < SIZE - 1; ++i)
        {
            result.digits[i + 1] += result.digits[i] / BASE;
            result.digits[i] %= BASE;
        }
        return result;
    }
    void operator/=(long long x)
    {
        for (int i = SIZE - 1; i >= 0; --i)
        {
            if (i)
                digits[i - 1] += (digits[i] % x) * BASE;
            digits[i] /= x;
        }
    }
    BigInt operator/(long long x)
    {
        BigInt n(*this);
        n /= x;
        return n;
    }
};

std::ostream &operator<<(std::ostream &out, const BigInt &num)
{
    std::string result;
    char buffer[10];
    for (int i = BigInt::SIZE - 1; i >= 0; --i)
    {
        sprintf(buffer, "%09d", num.digits[i]);
        result += buffer;
    }
    int first_idx = result.find_first_not_of('0');
    (first_idx == std::string::npos) ? (out << '0') : (out << result.substr(first_idx));
    return out;
}

int main()
{
    BigInt bignum = 1628346523748236424;
    std::cout << bignum;

    return EXIT_SUCCESS;
}