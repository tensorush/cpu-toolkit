/*
    Knuth-Morris-Pratt Algorithm
    ----------------------------
    Time: O(n+m)
    Space: O(n)
*/
#include <iostream>
#include <vector>
#include <string>

std::vector<size_t> KnuthMorrisPrattAlgorithm(const std::string& str) {
    size_t n_m = str.length();
    std::vector<size_t> prefixFunction(n_m);
    for (size_t i = 1; i < n_m; ++i) {
        size_t j = prefixFunction[i - 1];
        while (j > 0 && str[i] != str[j]) {
            j = prefixFunction[j - 1];
        }
        if (str[i] == str[j]) ++j;
        prefixFunction[i] = j;
    }
    return prefixFunction;
}

int main() {
    std::string word, text;
    std::cin >> word >> text;
    std::vector<size_t> prefixFunction = KnuthMorrisPrattAlgorithm(word + '#' + text);
    size_t m = word.length();
    for (size_t i = 0; i < text.length(); ++i) {
        if (prefixFunction[m + 1 + i] == m) {
            std::cout << "word = text[" << i - m + 1 << ".." << i << "]" << std::endl;
        }
    }
}