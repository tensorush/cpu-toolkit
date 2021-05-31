/*
    Manacher's Algorithm
    --------------------
    Time: O(n^2)
    Space: O(1)
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

std::string StringPreprocessing(const std::string& string) {
    const std::string start = "@", evenPos = "#", end = "$";
    std::string newString = start;
    for (const char& character : string) {
        newString += evenPos + character;
    }
    newString += evenPos + end;
    return newString;
}

std::string ManacherAlgorithm(const std::string& string) {
    std::string newString = StringPreprocessing(string);
    size_t center = 0, right = 0, range = newString.length() - 1;
    std::vector<size_t> palindrome(range);
    for (size_t i = 1; i < range; ++i) {
        size_t j = center - (i - center);
        if (i < right) palindrome[i] = std::min(right - i, palindrome[j]);
        while (newString[i + 1 + palindrome[i]] == newString[i - 1 - palindrome[i]]) ++palindrome[i];
        if (i + palindrome[i] > right) {
            center = i;
            right = center + palindrome[center];
        }
    }
    center = 0;
    size_t maxPalindrome = 0;
    for (size_t i = 1; i < range; ++i) {
        if (palindrome[i] > maxPalindrome) {
            center = i;
            maxPalindrome = palindrome[center];
        }
    }
    return string.substr((center - 1 - maxPalindrome) / 2, maxPalindrome);
}

int main() {
    std::string string;
    std::getline(std::cin, string);
    std::cout << ManacherAlgorithm(string) << std::endl;
    
    return EXIT_SUCCESS;
}