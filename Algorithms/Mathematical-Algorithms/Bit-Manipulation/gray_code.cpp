/*
    Gray Code
    -----------
    Time: O(1)
    Space: O(1)
*/
#include <iostream>

unsigned GrayCode(const unsigned& number) {
	return number ^ (number >> 1);
}

unsigned ReverseGrayCode(unsigned grayCode) {
	unsigned number;
	for (number = 0; grayCode; grayCode >>= 1) {
		number ^= grayCode;
    }
	return number;
}

int main() {
    unsigned number;
    std::cin >> number;
    std::cout << GrayCode(number) << ' ' << ReverseGrayCode(GrayCode(number)) << std::endl;

    return EXIT_SUCCESS;
}