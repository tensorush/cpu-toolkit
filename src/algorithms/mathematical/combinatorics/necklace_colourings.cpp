/*
    Necklace Colourings
    -------------------------------
    Time: O(numBeads*log(numBeads))
    Space: O(1)
*/
#include <iostream>
#include <vector>
#include <cmath>

unsigned EuclideanAlgorithm(unsigned a, unsigned b) {
    while (a > 0) {
        b %= a;
        std::swap(a, b);
    }
    return b;
}

unsigned NecklaceColourings(const unsigned& n, const unsigned& k) {
    unsigned numColourings = 0;
    for (unsigned i = 1; i <= n; ++i) {
        numColourings += std::pow(k, EuclideanAlgorithm(i, n));
    }
    return numColourings / n;
}

int main() {
    unsigned numBeads, numColours;
    std::cin >> numBeads >> numColours;
    std::cout << NecklaceColourings(numBeads, numColours) << std::endl;

    return EXIT_SUCCESS;
}