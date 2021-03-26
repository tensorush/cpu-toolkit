/*
    Largest Number
    ------------------
    Time: O(numDigits)
    Space: O(1)
*/
#include <iostream>
#include <vector>
#include <string>

std::string LargestNumber(const size_t& numDigits) {
    std::vector<size_t> digitCounter(10);
    for (size_t i = 0; i < numDigits; ++i) {
        size_t digit;
        std::cin >> digit;
        ++digitCounter[digit];
    }
    std::string largest;
    for (size_t i = 9; i >= 0; --i) {
        largest += std::string(digitCounter[i], (char) (i + 48));
    }
    return largest;
}

int main() {
    size_t numDigits;
    std::cin >> numDigits;
    std::cout << LargestNumber(numDigits) << std::endl;

    return 0;
}