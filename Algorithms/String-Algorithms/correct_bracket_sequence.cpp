/*
    Correct Bracket Sequence
    ------------------------
    Time: O(n)
    Space: O(n)
*/
#include <iostream>
#include <string>
#include <stack>

bool CorrectBracketSequence(const std::string& str) {
    std::stack<char> stack;
    std::string open = "([{", close = ")]}";
    for (const char& c : str) {
        if (open.find(c) != std::string::npos) {
            stack.push(c);
        } else if (close.find(c) != std::string::npos) {
            if (stack.empty() || stack.top() != open[close.find(c)]) return false;
            stack.pop();
        }
    }
    return (stack.empty())?(true):(false);
}

int main() {
    std::string str;
    std::cin >> str;
    std::cout << CorrectBracketSequence(str) << std::endl;
    
    return 0;
}