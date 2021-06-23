/*
    Binary Arithmetic
    -----------------
*/
#include <iostream>
#include <bitset>
#include <string>
#include <array>

int main()
{
    // For efficient standard library implementations
    // consult the <bitset> and <bit> (C++20) headers.
    unsigned number;
    std::cin >> number;

    // Flip bits
    unsigned flipped = ~number;

    // Parity check
    bool isOdd = number & 1;

    // Divide by two
    unsigned halved = number >> 1;

    // Multiply by two
    unsigned doubled = number << 1;

    // Hamming distance
    unsigned anotherNumber = 33, numDifferentBits = 0;
    for (unsigned sum = number + anotherNumber; sum > 0; ++numDifferentBits)
    {
        sum &= sum - 1;
    }

    // Power of two check
    bool isPowerOfTwo = number && !(number & (number - 1));

    // Find first set bit
    unsigned firstSetBit = 0;
    if (number != 0)
    {
        unsigned powerOfTwo = 1;
        while (number & powerOfTwo == 0)
        {
            powerOfTwo <<= 1;
            ++firstSetBit;
        }
    }

    // Invert a single bit
    unsigned position = 0;
    unsigned inverted = number ^ (1 << position);

    // Set bits counting algorithm
    unsigned numSetBits = 0;
    while (number != 0)
    {
        number &= number - 1;
        ++numSetBits;
    }

    // Convert from decimal to binary
    const unsigned integerSize = 32;
    std::string binary = std::bitset<integerSize>(number).to_string();
    auto firstOne = binary.find('1');
    binary = (firstOne != std::string::npos) ? (binary.substr(firstOne)) : ("0");

    // Uniform-value knapsack problem
    const unsigned numItems = 3, capacity = 11;
    std::bitset<capacity> knapsack(1);
    std::array<unsigned, numItems> items = {3, 4, 7};
    for (const unsigned &item : items)
    {
        knapsack |= knapsack << item;
    }

    // Length-3 cycle check in a simple directed graph
    bool hasLength3Cycle = false;
    const unsigned numVertices = 3;
    std::array<std::bitset<numVertices>, numVertices> adjMatrix = {0b011, 0b101, 0b110};
    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = 0; j < numVertices; ++j)
        {
            if (adjMatrix[i][j] && (~adjMatrix[i] & adjMatrix[j]).any())
            {
                hasLength3Cycle = true;
                break;
            }
        }
    }

    // Modular determined system of linear equations (mod 2)
    const unsigned n = 3;
    std::array<std::bitset<n + 1>, n> A_b = {0b1010, 0b0011, 0b0100};
    for (unsigned j = 0; j < n; ++j)
    {
        unsigned nonzero = j;
        for (unsigned i = j + 1; i < n; ++i)
        {
            if (A_b[i][j])
                nonzero = i;
        }
        std::swap(A_b[nonzero], A_b[j]);
        for (unsigned i = 0; i < n; ++i)
        {
            if (i != j && A_b[i][j])
                A_b[i] ^= A_b[j];
        }
    }
    std::bitset<n> x;
    for (unsigned i = 0; i < n; ++i)
    {
        x[i] = A_b[i][n] ^ A_b[i][i];
    }

    return EXIT_SUCCESS;
}