/*
    Bishops Problem
    ------------------------------
    Time: O(boardSize*numBishops)
    Space: O(boardSize*numBishops)
*/
#include <iostream>
#include <vector>

unsigned BishopsProblem(const unsigned& n, const unsigned& k) {
    unsigned numPlacements = 0, maxBlackDiags = 2 * n - 1, maxWhiteDiags = 2 * n - 2;
    if (k > maxBlackDiags)
        return numPlacements;
    std::vector<std::vector<unsigned>> placeOnDiags(2 * n, std::vector<unsigned>(k + 1));
    for (auto& placeOnPrevDiags : placeOnDiags) {
        placeOnPrevDiags[0] = 1;
    }
    placeOnDiags[1][1] = 1;
    std::vector<unsigned> cellsOnDiags(2 * n);
    for (unsigned diag = 2; diag <= maxBlackDiags; ++diag) {
        cellsOnDiags[diag] = (diag % 2 == 1) ? (diag / 4 * 2 + 1) : ((diag - 1) / 4 * 2 + 2);
    }
    for (unsigned diag = 2; diag <= maxBlackDiags; ++diag) {
        for (unsigned bishops = 1; bishops <= k; ++bishops) {
            placeOnDiags[diag][bishops] = placeOnDiags[diag - 2][bishops] + placeOnDiags[diag - 2][bishops - 1] * (cellsOnDiags[diag] - bishops + 1);
        }
    }
    for (unsigned bishops = 0; bishops <= k; ++bishops) {
        numPlacements += placeOnDiags[maxBlackDiags][bishops] * placeOnDiags[maxWhiteDiags][k - bishops];
    }
    return numPlacements;
}

int main() {
    unsigned boardSize, numBishops;
    std::cin >> boardSize >> numBishops;
    std::cout << BishopsProblem(boardSize, numBishops) << std::endl;

    return EXIT_SUCCESS;
}