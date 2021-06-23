/*
    Boyer-Moore Algorithm
    ---------------------------
    Time: Ω(n/m) Θ(n*m) O(n*m)
    Space: O(1)
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

auto BoyerMooreAlgorithm(const std::string &pattern, const std::string &text)
{
    int n = text.length(), m = pattern.length();
    std::vector<int> badChars(256, -1);
    for (int j = 0; j < m; ++j)
    {
        badChars[static_cast<int>(pattern[j])] = j;
    }
    int i = 0, j = m - 1;
    std::vector<int> matchIndices;
    while (i <= n - m)
    {
        j = m - 1;
        while (j >= 0 && pattern[j] == text[i + j])
            --j;
        if (j < 0)
        {
            matchIndices.emplace_back(i);
            i += (i + m >= n) ? (1) : (m - badChars[text[i + m] - '\0']);
        }
        else
        {
            i += std::max(1, j - badChars[text[i + j] - '\0']);
        }
    }
    return matchIndices;
}

int main()
{
    std::string pattern, text;
    std::getline(std::cin, pattern);
    std::getline(std::cin, text);
    auto matchIndices = BoyerMooreAlgorithm(pattern, text);
    for (const int &index : matchIndices)
    {
        std::cout << index << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}