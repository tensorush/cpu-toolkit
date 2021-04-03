/*
    Z-function
    -----------
    Time: O(n)
    Space: O(n)
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

std::vector<size_t> ZFunction(std::string str) {
	size_t n_m = str.length();
	std::vector<size_t> zFunction(n_m);
	for (size_t i = 1, l = 0, r = 0; i < n_m; ++i) {
		if (i <= r) zFunction[i] = std::min(zFunction[i - l], r - i + 1);
		while (i + zFunction[i] < n_m && str[zFunction[i]] == str[i + zFunction[i]]) ++zFunction[i];
		if (i + zFunction[i] - 1 > r) l = i, r = i + zFunction[i] - 1;
	}
	return zFunction;
}

int main() {
    std::string word, text;
    std::cin >> word >> text;
    std::vector<size_t> zFunction = ZFunction(word + '#' + text);
    size_t n = text.length(), m = word.length();
    for (size_t i = 0; i < n; ++i) {
        if (zFunction[m + 1 + i] == m) {
            std::cout << "word = text[" << i << ".." << i + m - 1 << "]" << std::endl;
        }
    }

    return 0;
}