/*
    Three-Digit Armstrong Numbers
    -----------------------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>
#include <vector>

void ThreeDigitArmstrongNumbers(std::vector<unsigned>& numbers) {
    unsigned sumOfCubedDigits;
    for (unsigned number = 100; number < 1000; ++number) {
        sumOfCubedDigits = 0;
        for (unsigned digit, digits = number; digits > 0; digits /= 10) {
            digit = digits % 10;
            sumOfCubedDigits += digit * digit * digit;
        }
        if (sumOfCubedDigits == number)
            numbers.emplace_back(number);
    }
}

int main() {
    std::vector<unsigned> threeDigitArmstrongNumbers;
    ThreeDigitArmstrongNumbers(threeDigitArmstrongNumbers);
    for (const unsigned& number : threeDigitArmstrongNumbers) {
        std::cout << number << ' ';
    }
    std::cout << '\n';

    return EXIT_SUCCESS;
}