/*
    Largest Number
    ------------------
    Time: O(numDigits)
    Space: O(1)
*/
#include <iostream>
#include <vector>
#include <string>

std::string LargestNumber(const std::vector<unsigned>& digits) {
    std::vector<unsigned> digitCounter(10);
    for (const unsigned& digit : digits) {
        ++digitCounter[digit];
    }
    std::string largest;
    for (int i = 9; i >= 0; --i) {
        largest += std::string(digitCounter[i], std::to_string(i)[0]);
    }
    return largest;
}

int main() {
    unsigned numDigits;
    std::cin >> numDigits;
    std::vector<unsigned> digits(numDigits);
    for (unsigned& digit : digits) {
        std::cin >> digit;
    }
    std::cout << LargestNumber(digits) << std::endl;

    return EXIT_SUCCESS;
}