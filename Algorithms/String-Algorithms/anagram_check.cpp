/*
    Anagram Check
    ------------------
    Time: O(max(n, m))
    Space: O(1)
*/
#include <iostream>
#include <vector>
#include <string>

bool AnagramCheck(const std::string &string_1, const std::string &string_2)
{
    std::vector<unsigned> counter_1(26);
    for (const char &character : string_1)
    {
        if (character != ' ')
            ++counter_1[tolower(character) - 'a'];
    }
    std::vector<unsigned> counter_2(26);
    for (const char &character : string_2)
    {
        if (character != ' ')
            ++counter_2[tolower(character) - 'a'];
    }
    return (counter_1 == counter_2);
}

int main()
{
    std::string string_1, string_2;
    std::getline(std::cin, string_1);
    std::getline(std::cin, string_2);
    std::cout << std::boolalpha << AnagramCheck(string_1, string_2) << std::endl;

    return EXIT_SUCCESS;
}