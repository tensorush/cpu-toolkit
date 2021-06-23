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

auto RabinKarpAlgorithm(const std::string &pattern, const std::string &text)
{
    const unsigned prime = 53;
    std::vector<unsigned> primePowers(std::max(pattern.length(), text.length()));
    primePowers[0] = 1;
    for (size_t i = 1; i < primePowers.size(); ++i)
    {
        primePowers[i] = primePowers[i - 1] * prime;
    }
    std::vector<unsigned> prefixHashes(text.length());
    for (size_t i = 0; i < text.length(); ++i)
    {
        prefixHashes[i] = (text[i] - 'a' + 1) * primePowers[i];
        if (i)
            prefixHashes[i] += prefixHashes[i - 1];
    }
    unsigned patternHash = 0;
    for (size_t i = 0; i < pattern.length(); ++i)
    {
        patternHash += (pattern[i] - 'a' + 1) * primePowers[i];
    }
    std::vector<size_t> matchPositions;
    for (size_t i = 0; i + pattern.length() - 1 < text.length(); ++i)
    {
        unsigned curHash = prefixHashes[i + pattern.length() - 1];
        if (i)
            curHash -= prefixHashes[i - 1];
        if (curHash == patternHash * primePowers[i])
            matchPositions.emplace_back(i);
    }
    return matchPositions;
}

int main()
{
    std::string pattern, text;
    std::getline(std::cin, pattern);
    std::getline(std::cin, text);
    auto matchPositions = RabinKarpAlgorithm(pattern, text);
    for (const size_t &i : matchPositions)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}