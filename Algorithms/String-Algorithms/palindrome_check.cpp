/*
    Palindrome Check
    ----------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>
#include <string>

bool PalindromeCheck(const std::string& string) {
    bool isPalindrome = true;
    for (int start = 0, end = string.length() - 1; start < end; ++start, --end) {
        if (string[start] != string[end]) {
            isPalindrome = false;
            break;
        }
    }
    return isPalindrome;
}

int main() {
    std::string string;
    std::getline(std::cin, string);
    std::cout << std::boolalpha << PalindromeCheck(string) << std::endl;

    return EXIT_SUCCESS;
}