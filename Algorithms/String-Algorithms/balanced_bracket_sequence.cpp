/*
    Balanced Bracket Sequence
    -------------------------
    Time: O(n)
    Space: O(n)
*/
#include <iostream>
#include <string>
#include <stack>

bool BalancedBracketSequence(const std::string &string)
{
    std::stack<char> stack;
    std::string open = "([{", close = ")]}";
    for (const char &c : string)
    {
        if (open.find(c) != std::string::npos)
        {
            stack.push(c);
        }
        else if (close.find(c) != std::string::npos)
        {
            if (stack.empty() || stack.top() != open[close.find(c)])
                return false;
            stack.pop();
        }
    }
    return (stack.empty()) ? (true) : (false);
}

int main()
{
    std::string string;
    std::getline(std::cin, string);
    std::cout << BalancedBracketSequence(string) << std::endl;

    return EXIT_SUCCESS;
}