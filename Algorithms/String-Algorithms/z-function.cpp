/*
    Z-Function
    -----------
    Time: O(n)
    Space: O(n)
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

auto ZFunction(std::string str) {
    unsigned n_m = str.length();
    std::vector<unsigned> zFunction(n_m);
    for (unsigned i = 1, l = 0, r = 0; i < n_m; ++i) {
        if (i <= r)
            zFunction[i] = std::min(zFunction[i - l], r - i + 1);
        while (i + zFunction[i] < n_m && str[zFunction[i]] == str[i + zFunction[i]])
            ++zFunction[i];
        if (i + zFunction[i] - 1 > r) {
            l = i;
            r = i + zFunction[i] - 1;
        }
    }
    return zFunction;
}

int main() {
    std::string word, text;
    std::getline(std::cin, word);
    std::getline(std::cin, text);
    auto zFunction = ZFunction(word + '#' + text);
    unsigned n = text.length(), m = word.length();
    for (unsigned i = 0; i < n; ++i) {
        if (zFunction[m + 1 + i] == m)
            std::cout << "word = text[" << i << ".." << i + m - 1 << "]" << std::endl;
    }

    return EXIT_SUCCESS;
}