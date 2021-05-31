/*
    Dice Rolling Problem
    ---------------------------
    Time: O(numDice*numFaces^2)
    Space: O(numDice*targetSum)
*/
#include <algorithm>
#include <iostream>
#include <vector>

int DiceRollingProblem(const int& numDice, const int& numFaces, const int& targetSum) {
    std::vector<std::vector<int>> sums(numDice + 1, std::vector<int>(targetSum + 1));
    for (int sum = 1; sum <= std::min(numFaces, targetSum); ++sum) {
        ++sums[1][sum];
    }
    for (int dice = 2; dice <= numDice; ++dice) {
        for (int sum = 1; sum <= targetSum; ++sum) {
            int numWays = 0;
            for (int value = 1; value <= numFaces && sum - value >= 0; ++value) {
                numWays += sums[dice - 1][sum - value];
            }
            sums[dice][sum] = numWays;
        }
    }
    return sums[numDice][targetSum];
}

int main() {
    int numDice, numFaces, targetSum;
    std::cin >> numDice >> numFaces >> targetSum;
    std::cout << DiceRollingProblem(numDice, numFaces, targetSum) << std::endl;

    return EXIT_SUCCESS;
}