/*
    Bishops On A Chessboard
    ------------------------------
    Time: O(boardSize*numBishops)
    Space: O(boardSize*numBishops)
*/
#include <iostream>
#include <vector>

size_t BishopsOnChessboard(const size_t& n, const size_t& k) {
    if (k > 2 * n - 1) {
    	std::cout << 0;
	    return 0;
    }
    std::vector<std::vector<size_t>> placeOnDiags(n * 2, std::vector<size_t>(k + 2));
    for (size_t i = 0; i < n * 2; ++i) {
        placeOnDiags[i][0] = 1;
    }
    placeOnDiags[1][1] = 1;
    for (size_t i = 2; i < n * 2; ++i) {
        for (size_t j = 1; j <= k; ++j) {
            size_t diag = (i & 1)?(i / 4 * 2 + 1):((i - 1) / 4 * 2 + 2);
            placeOnDiags[i][j] = placeOnDiags[i - 2][j] + placeOnDiags[i - 2][j - 1] * (diag - j + 1);
        }
    }
    size_t numPlacements = 0;
    for (size_t i = 0; i <= k; ++i)
        numPlacements += placeOnDiags[n * 2 - 1][i] * placeOnDiags[n * 2 - 2][k - i];
    return numPlacements;
}

int main() {
    size_t boardSize, numBishops;
    std::cin >> boardSize >> numBishops;
    std::cout << BishopsOnChessboard(boardSize, numBishops) << std::endl;

    return 0;
}