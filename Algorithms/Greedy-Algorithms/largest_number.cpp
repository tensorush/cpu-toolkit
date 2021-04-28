/*
    Largest Number
    ------------------
    Time: O(numDigits)
    Space: O(1)
*/
#include <iostream>
#include <vector>
#include <string>

std::string LargestNumber(const unsigned& numDigits) {
    std::vector<unsigned> digitCounter(10);
    for (unsigned i = 0; i < numDigits; ++i) {
        unsigned digit;
        std::cin >> digit;
        ++digitCounter[digit];
    }
    std::string largest;
    for (int i = 9; i >= 0; --i) {
        largest += std::string(digitCounter[i], (char) (i + 48));
    }
    return largest;
}

int main() {
    unsigned numDigits;
    std::cin >> numDigits;
    std::cout << LargestNumber(numDigits) << std::endl;

    return 0;
}