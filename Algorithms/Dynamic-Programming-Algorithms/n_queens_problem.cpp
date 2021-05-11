/*
    N Queens Problem
    -------------------
    Time: O(boardSize)
    Space: O(boardSize)
*/
#include <iostream>
#include <vector>

void NQueensProblem(unsigned boardSize, unsigned& numWays, std::vector<bool>& column, std::vector<bool>& diag_1, std::vector<bool>& diag_2, unsigned row = 0) {
    if (row == boardSize) {
        ++numWays;
        return ;
    }
    for (unsigned col = 0; col < boardSize; ++col) {
        if (column[col] && diag_1[row - col + boardSize - 1] && diag_2[row + col]) {
            column[col] = diag_1[row - col + boardSize - 1] = diag_2[row + col] = false;
            NQueensProblem(boardSize, numWays, column, diag_1, diag_2, row + 1);
            column[col] = diag_1[row - col + boardSize - 1] = diag_2[row + col] = true;
        }
    }
}

int main() {
    unsigned boardSize;
    std::cin >> boardSize;
    unsigned numWays = 0;
    std::vector<bool> column(boardSize, true), diag_1(boardSize, true), diag_2(boardSize, true);
    NQueensProblem(boardSize, numWays, column, diag_1, diag_2);
    std::cout << numWays << std::endl;

    return 0;
}