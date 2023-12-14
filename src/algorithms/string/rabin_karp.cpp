/*
    Rabin-Karp Algorithm
    ---------------------------------
    Time: Time: Ω(n+m) Θ(n+m) O(n*m)
    Space: O(n)
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

auto RabinKarpAlgorithm(const std::string& pattern, const std::string& text) {
    unsigned n = text.length(), m = pattern.length(), prime = 53;
    std::vector<unsigned> primePowers(std::max(m, n));
    primePowers[0] = 1;
    for (unsigned i = 1; i < primePowers.size(); ++i) {
        primePowers[i] = primePowers[i - 1] * prime;
    }
    std::vector<unsigned> prefixHashes(n);
    for (unsigned i = 0; i < n; ++i) {
        prefixHashes[i] = (text[i] - 'a' + 1) * primePowers[i];
        if (i)
            prefixHashes[i] += prefixHashes[i - 1];
    }
    unsigned patternHash = 0;
    for (unsigned i = 0; i < m; ++i) {
        patternHash += (pattern[i] - 'a' + 1) * primePowers[i];
    }
    std::vector<unsigned> matchPositions;
    for (unsigned i = 0; i + m - 1 < n; ++i) {
        unsigned curHash = prefixHashes[i + m - 1];
        if (i)
            curHash -= prefixHashes[i - 1];
        if (curHash == patternHash * primePowers[i])
            matchPositions.emplace_back(i);
    }
    return matchPositions;
}

int main() {
    std::string pattern, text;
    std::getline(std::cin, pattern);
    std::getline(std::cin, text);
    auto matchPositions = RabinKarpAlgorithm(pattern, text);
    for (const unsigned& i : matchPositions) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}