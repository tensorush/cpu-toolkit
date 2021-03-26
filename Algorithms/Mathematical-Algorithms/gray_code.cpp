/*
    Gray Code
    -----------
    Time: O(1)
    Space: O(1)
*/
#include <iostream>

int GrayCode(int n) {
	return n ^ (n >> 1);
}

int ReverseGrayCode(int g) {
	int n;
	for (n = 0; g; g >>= 1) {
		n ^= g;
    }
	return n;
}

int main() {
    size_t n;
    std::cin >> n;
    std::cout << GrayCode(n) << ' ' << ReverseGrayCode(GrayCode(n)) << std::endl;

    return 0;
}