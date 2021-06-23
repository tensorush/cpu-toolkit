/*
    Boolean Parenthesization Problem
    --------------------------------
    Time: O(n^3)
    Space: O(n^2)
*/
#include <iostream>
#include <vector>

enum class Operator
{
    AND = 0,
    OR = 1,
    XOR = 2
};

int BooleanParenthesizationProblem(const std::vector<bool> &operands, const std::vector<Operator> &operators)
{
    unsigned n = operands.size();
    std::vector<std::vector<int>> numTrueSubexprs(n, std::vector<int>(n));
    std::vector<std::vector<int>> numFalseSubexprs = numTrueSubexprs;
    for (unsigned i = 0; i < n; ++i)
    {
        (operands[i] == true) ? (++numTrueSubexprs[i][i]) : (++numFalseSubexprs[i][i]);
    }
    for (unsigned range = 2; range <= n; ++range)
    {
        for (unsigned i = 0; i <= n - range; ++i)
        {
            for (unsigned j = i + range - 1, k = i; k < j; ++k)
            {
                switch (operators[k])
                {
                case Operator::AND:
                    numTrueSubexprs[i][j] += numTrueSubexprs[i][k] * numTrueSubexprs[k + 1][j];
                    numFalseSubexprs[i][j] += (numTrueSubexprs[i][k] + numFalseSubexprs[i][k]) *
                                                  (numTrueSubexprs[k + 1][j] + numFalseSubexprs[k + 1][j]) -
                                              (numTrueSubexprs[i][k] * numTrueSubexprs[k + 1][j]);
                    break;
                case Operator::OR:
                    numTrueSubexprs[i][j] += (numTrueSubexprs[i][k] + numFalseSubexprs[i][k]) *
                                                 (numTrueSubexprs[k + 1][j] + numFalseSubexprs[k + 1][j]) -
                                             (numFalseSubexprs[i][k] * numFalseSubexprs[k + 1][j]);
                    numFalseSubexprs[i][j] += numFalseSubexprs[i][k] * numFalseSubexprs[k + 1][j];
                    break;
                case Operator::XOR:
                    numTrueSubexprs[i][j] += (numTrueSubexprs[i][k] * numFalseSubexprs[k + 1][j]) +
                                             (numFalseSubexprs[i][k] * numTrueSubexprs[k + 1][j]);
                    numFalseSubexprs[i][j] += (numTrueSubexprs[i][k] * numTrueSubexprs[k + 1][j]) +
                                              (numFalseSubexprs[i][k] * numFalseSubexprs[k + 1][j]);
                    break;
                }
            }
        }
    }
    return numTrueSubexprs[0][n - 1];
}

int main()
{
    std::vector<bool> operands = {true, true, false, false};
    std::vector<Operator> operators = {Operator::XOR, Operator::AND, Operator::XOR};
    std::cout << BooleanParenthesizationProblem(operands, operators) << std::endl;

    return EXIT_SUCCESS;
}