/*
    Boolean Parenthesization Problem
    --------------------------------
    Time: O(n^3)
    Space: O(n^2)
*/
#include <iostream>
#include <vector>

enum class Operator { AND = 0, OR = 1, XOR = 2 };

int BooleanParenthesizationProblem(const std::vector<bool>& operands, const std::vector<Operator>& operators) {
    unsigned n = operands.size();
    std::vector<std::vector<int>> trueExprs(n, std::vector<int>(n));
    std::vector<std::vector<int>> falseExprs = trueExprs;
    for (unsigned i = 0; i < n; ++i) {
        (operands[i] == true) ? (++trueExprs[i][i]) : (++falseExprs[i][i]);
    }
    for (unsigned range = 2; range <= n; ++range) {
        for (unsigned i = 0; i <= n - range; ++i) {
            for (unsigned j = i + range - 1, k = i; k < j; ++k) {
                switch (operators[k]) {
                    case Operator::AND:
                        trueExprs[i][j] += trueExprs[i][k] * trueExprs[k + 1][j];
                        falseExprs[i][j] += (trueExprs[i][k] + falseExprs[i][k]) * (trueExprs[k + 1][j] + falseExprs[k + 1][j]) - (trueExprs[i][k] * trueExprs[k + 1][j]);
                        break;
                    case Operator::OR:
                        trueExprs[i][j] += (trueExprs[i][k] + falseExprs[i][k]) * (trueExprs[k + 1][j] + falseExprs[k + 1][j]) - (falseExprs[i][k] * falseExprs[k + 1][j]);
                        falseExprs[i][j] += falseExprs[i][k] * falseExprs[k + 1][j];
                        break;
                    case Operator::XOR:
                        trueExprs[i][j] += (trueExprs[i][k] * falseExprs[k + 1][j]) + (falseExprs[i][k] * trueExprs[k + 1][j]);
                        falseExprs[i][j] += (trueExprs[i][k] * trueExprs[k + 1][j]) + (falseExprs[i][k] * falseExprs[k + 1][j]);
                        break;
                }
            }
        }
    }
    return trueExprs[0][n - 1];
}

int main() {
    std::vector<bool> operands = { true, true, false, false };
    std::vector<Operator> operators = { Operator::XOR, Operator::AND, Operator::XOR };
    std::cout << BooleanParenthesizationProblem(operands, operators) << std::endl;

    return EXIT_SUCCESS;
}