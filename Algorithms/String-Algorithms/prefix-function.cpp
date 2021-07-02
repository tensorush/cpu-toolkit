/*
    Prefix-Function
    ---------------
    Time: O(n+m)
    Space: O(n)
*/
#include <iostream>
#include <vector>
#include <string>

auto PrefixFunction(const std::string& str) {
    unsigned n_m = str.length();
    std::vector<unsigned> prefixFunction(n_m);
    for (unsigned i = 1; i < n_m; ++i) {
        unsigned j = prefixFunction[i - 1];
        while (j > 0 && str[i] != str[j])
            j = prefixFunction[j - 1];
        if (str[i] == str[j])
            ++j;
        prefixFunction[i] = j;
    }
    return prefixFunction;
}

int main() {
    std::string word, text;
    std::getline(std::cin, word);
    std::getline(std::cin, text);
    auto prefixFunction = PrefixFunction(word + '#' + text);
    unsigned m = word.length();
    for (unsigned i = 0; i < text.length(); ++i) {
        if (prefixFunction[m + 1 + i] == m)
            std::cout << "word = text[" << i - m + 1 << ".." << i << "]" << std::endl;
    }

    return EXIT_SUCCESS;
}