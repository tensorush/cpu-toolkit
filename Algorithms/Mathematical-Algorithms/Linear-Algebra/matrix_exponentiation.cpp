/*
    Matrix Exponentiation
    -----------------------
    Time: O(n^3 log(power))
    Space: O(n^2)
*/
#include <iostream>
#include <vector>

template <typename T>
auto MatrixProduct(const std::vector<std::vector<T>> &A, const std::vector<std::vector<T>> &B)
{
    size_t n = A.size(), m = B[0].size(), l = B.size();
    std::vector<std::vector<T>> C(n, std::vector<T>(n));
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            for (size_t k = 0; k < l; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

template <typename T>
void MatrixExponentiation(std::vector<std::vector<T>> A, std::vector<std::vector<T>> &B, unsigned power)
{
    size_t n = A.size();
    while (power)
    {
        if (power % 2 == 1)
            B = MatrixProduct(B, A);
        A = MatrixProduct(A, A);
        power /= 2;
    }
}

int main()
{
    unsigned n, power;
    std::cin >> n >> power;
    std::vector<std::vector<double>> matrix(n, std::vector<double>(n)), exponent(n, std::vector<double>(n));
    for (std::vector<double> &row : matrix)
    {
        for (double &element : row)
        {
            std::cin >> element;
        }
    }
    for (size_t i = 0; i < n; ++i)
    {
        exponent[i][i] = 1;
    }
    MatrixExponentiation(matrix, exponent, power);
    for (std::vector<double> &row : exponent)
    {
        for (double &element : row)
        {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}