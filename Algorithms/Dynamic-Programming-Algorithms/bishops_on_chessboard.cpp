/*
    Bishops On A Chessboard
    ------------------------------
    Time: O(boardSize*numBishops)
    Space: O(boardSize*numBishops)
*/
#include <iostream>
#include <vector>

unsigned BishopsOnChessboard(const unsigned& n, const unsigned& k) {
    unsigned numPlacements = 0;
    if (k > 2 * n - 1) return numPlacements;
    std::vector<std::vector<unsigned>> placeOnDiags(n * 2, std::vector<unsigned>(k + 2));
    for (unsigned i = 0; i < n * 2; ++i) {
        placeOnDiags[i][0] = 1;
    }
    placeOnDiags[1][1] = 1;
    for (unsigned i = 2; i < n * 2; ++i) {
        for (unsigned j = 1; j <= k; ++j) {
            unsigned diag = (i & 1)?(i / 4 * 2 + 1):((i - 1) / 4 * 2 + 2);
            placeOnDiags[i][j] = placeOnDiags[i - 2][j] + placeOnDiags[i - 2][j - 1] * (diag - j + 1);
        }
    }
    for (unsigned i = 0; i <= k; ++i) {
        numPlacements += placeOnDiags[n * 2 - 1][i] * placeOnDiags[n * 2 - 2][k - i];
    }
    return numPlacements;
}

int main() {
    unsigned boardSize, numBishops;
    std::cin >> boardSize >> numBishops;
    std::cout << BishopsOnChessboard(boardSize, numBishops) << std::endl;

    return 0;
}