/*
    Binary Arithmetic
    -----------------
*/
#include <iostream>
#include <climits>
#include <bitset>
#include <string>
#include <array>

int main() {
    // For efficient standard library implementations
    // consult the <bitset> and <bit> (C++20) headers.
    int integer, integer_2;
    unsigned number, number_2;
    const unsigned integerSize = sizeof(int) * CHAR_BIT;
    unsigned numUnsignedIntegerValueBits = integerSize - 1;
    std::cin >> integer >> integer_2 >> number >> number_2;

    // Negation
    int negated = ~integer + 1;

    // Merge bits
    unsigned mask = 0b1010; // 0 where bits from number should be selected, 1 - from number_2.
    unsigned merged = number ^ ((number ^ number_2) & mask);

    // Parity check
    bool isOdd = number & 1;

    // Bit reversal
    unsigned reversed = number;
    for (number >>= 1; number != 0; number >>= 1) {
        reversed <<= 1;
        reversed |= number & 1;
        --numUnsignedIntegerValueBits;
    }
    reversed <<= numUnsignedIntegerValueBits;

    // Bit inversion
    unsigned flipped = ~number;

    // Morton number
    unsigned int mortonNumber = 0; // Bits of number are in the even positions, number_2 - in the odd.
    for (int bit = 0; bit < numUnsignedIntegerValueBits; ++bit) {
        mortonNumber |= (number & 1 << bit) << bit | (number_2 & 1 << bit) << (bit + 1);
    }

    // Minimum value
    int minimum = integer_2 + ((integer - integer_2) & ((integer - integer_2) >> numUnsignedIntegerValueBits));

    // Maximum value
    int maximum = integer - ((integer - integer_2) & ((integer - integer_2) >> numUnsignedIntegerValueBits));

    // Absolute value
    int signBit = integer >> numUnsignedIntegerValueBits;
    unsigned absolute = (integer + signBit) ^ signBit;

    // Sign-bit retrieval
    signBit = ((integer == 0) ? (0) : (1)) | (integer >> numUnsignedIntegerValueBits);

    // Hamming distance
    unsigned numDifferentBits = 0;
    for (unsigned sum = number + number_2; sum > 0; ++numDifferentBits) {
        sum &= sum - 1;
    }

    // Swap two integers
    integer ^= integer_2 ^= integer ^= integer_2;

    // Power of two check
    bool isPowerOfTwo = number && !(number & (number - 1));

    // Euclidean algorithm
    int gcd = integer;
    while (integer_2 %= gcd ^= integer_2 ^= gcd ^= integer_2);

    // Single-bit inversion
    unsigned position = 0;
    unsigned inverted = number ^ (1 << position);

    // Multiplication by two
    unsigned doubled = number << 1;

    // Integer division by two
    unsigned halved = number >> 1;

    // Binary palindrome check
    bool isBinaryPalindrome;
    int binaryReverse = 0, temp = integer;
    while (temp > 0) {
        binaryReverse = (binaryReverse << 1) | (temp & 1);
        temp >>= 1;
    }
    isBinaryPalindrome = (binaryReverse == integer);

    // Signedness comparison check
    bool haveDifferentSign = (integer ^ integer_2 < 0);

    // Decimal-to-binary conversion
    std::string binary = std::bitset<integerSize>(number).to_string();
    auto firstOne = binary.find('1');
    binary = (firstOne != std::string::npos) ? (binary.substr(firstOne)) : ("0");

    // Binary-to-decimal conversion
    unsigned int decimal = std::bitset<integerSize>(binary).to_ulong();

    // Number of trailing zero bits
    unsigned numTrailingZeroBits = numUnsignedIntegerValueBits;
    if (number > 0) {
        number = (number ^ (number - 1)) >> 1;  // Set number's trailing zeros to ones and the rest - to zeros.
        for (numTrailingZeroBits = 0; number != 0; ++numTrailingZeroBits) {
            number >>= 1;
        }
    }

    // Most significant power of two
    unsigned mostSignificantPowerOfTwo = (integer & (~integer + 1));

    // Uniform-value knapsack problem
    const unsigned numItems = 3, capacity = 11;
    std::bitset<capacity> knapsack(1);
    std::array<unsigned, numItems> items = { 3, 4, 7 };
    for (const unsigned& item : items) {
        knapsack |= knapsack << item;
    }

    // Least significant bit set (index)
    unsigned leastSignificantBitSet = 0;
    if (number != 0) {
        unsigned powerOfTwo = 1;
        while (number & powerOfTwo == 0) {
            powerOfTwo <<= 1;
            ++leastSignificantBitSet;
        }
    }

    // Modulo division by a power of two
    unsigned powerOfTwo = 32;
    unsigned remainder = number & (powerOfTwo - 1);

    // Modulo division by a power of two less one
    unsigned powerOfTwoLessOne = 31;
    for (remainder = number; number > powerOfTwoLessOne; number = remainder) {
        for (remainder = 0; number; number >>= numUnsignedIntegerValueBits) {
            remainder += number & powerOfTwoLessOne;
        }
    }
    remainder = (remainder == powerOfTwoLessOne) ? (0) : (remainder);

    // Brian Kernighan's bits set counting algorithm
    unsigned numBitsSet;
    for (numBitsSet = 0; number != 0; ++numBitsSet) {
        number &= number - 1;
    }

    // Logarithm base two or most significant bit set
    unsigned logarithmBaseTwo = 0;
    while (number >>= 1)
        ++logarithmBaseTwo;

    // Length-3 cycle check in a simple directed graph
    bool hasLength3Cycle = false;
    const unsigned numVertices = 3;
    std::array<std::bitset<numVertices>, numVertices> adjMatrix = { 0b011, 0b101, 0b110 };
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (adjMatrix[i][j] && (~adjMatrix[i] & adjMatrix[j]).any()) {
                hasLength3Cycle = true;
                break;
            }
        }
    }

    // Modular determined system of linear equations (mod 2)
    const unsigned n = 3;
    std::array<std::bitset<n + 1>, n> A_b = { 0b1010, 0b0011, 0b0100 };
    for (unsigned j = 0; j < n; ++j) {
        unsigned nonzero = j;
        for (unsigned i = j + 1; i < n; ++i) {
            if (A_b[i][j])
                nonzero = i;
        }
        std::swap(A_b[nonzero], A_b[j]);
        for (unsigned i = 0; i < n; ++i) {
            if (i != j && A_b[i][j])
                A_b[i] ^= A_b[j];
        }
    }
    std::bitset<n> x;
    for (unsigned i = 0; i < n; ++i) {
        x[i] = A_b[i][n] ^ A_b[i][i];
    }

    return EXIT_SUCCESS;
}