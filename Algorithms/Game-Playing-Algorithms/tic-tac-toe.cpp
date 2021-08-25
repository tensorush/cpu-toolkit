/*
    Tic-Tac-Toe
    -----------
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>

std::vector<std::vector<std::pair<unsigned, unsigned>>> winningStates = {
    { std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2) },
    { std::make_pair(1, 0), std::make_pair(1, 1), std::make_pair(1, 2) },
    { std::make_pair(2, 0), std::make_pair(2, 1), std::make_pair(2, 2) },
    { std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(2, 0) },
    { std::make_pair(0, 1), std::make_pair(1, 1), std::make_pair(2, 1) },
    { std::make_pair(0, 2), std::make_pair(1, 2), std::make_pair(2, 2) },
    { std::make_pair(0, 0), std::make_pair(1, 1), std::make_pair(2, 2) },
    { std::make_pair(2, 0), std::make_pair(1, 1), std::make_pair(0, 2) }
};

class TicTacToe {
public:
    enum PlayerStatus {
        LOST = 0, DREW = 1, WON = 2
    };
    enum BoardMarker {
        EMPTY = '_', PLAYER = 'X', PROGRAM = 'O'
    };
    static void printBoard(std::array<std::array<char, 3>, 3> board, std::ostream& out = std::cout) {
        out << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
        out << "----------" << std::endl;
        out << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
        out << "----------" << std::endl;
        out << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl << std::endl;
    }
    static std::vector<std::pair<unsigned, unsigned>> getLegalMoves(std::array<std::array<char, 3>, 3> board) {
        std::vector<std::pair<unsigned, unsigned>> legalMoves;
        for (unsigned i = 0; i < 3; ++i) {
            for (unsigned j = 0; j < 3; ++j) {
                if (board[i][j] != PROGRAM && board[i][j] != PLAYER)
                    legalMoves.emplace_back(std::make_pair(i, j));
            }
        }
        return legalMoves;
    }
    static bool isPositionOccupied(std::array<std::array<char, 3>, 3> board, std::pair<unsigned, unsigned> position) {
        std::vector<std::pair<unsigned, unsigned>> legalMoves = getLegalMoves(board);
        for (unsigned i = 0; i < legalMoves.size(); ++i) {
            if (position.first == legalMoves[i].first && position.second == legalMoves[i].second)
                return false;
        }
        return true;
    }
    static unsigned getBoardState(std::array<std::array<char, 3>, 3> board, char marker) {
        char opponentMarker = (marker == PROGRAM) ? (PLAYER) : (PROGRAM);
        if (hasWon(board, marker))
            return WON;
        return (hasWon(board, opponentMarker)) ? (LOST) : (DREW);
    }
    static std::pair<unsigned, std::pair<unsigned, unsigned>> minimaxAlgorithm(std::array<std::array<char, 3>, 3> board, char marker, unsigned depth = 0, unsigned alpha = LOST, unsigned beta = WON) {
        unsigned bestScore = (marker == PROGRAM) ? (LOST) : (WON);
        std::pair<unsigned, unsigned> bestMove = std::make_pair(-1, -1);
        if (getLegalMoves(board).empty() || getBoardState(board, PROGRAM) != DREW) {
            bestScore = getBoardState(board, PROGRAM);
            return std::make_pair(bestScore, bestMove);
        }
        unsigned score;
        std::pair<unsigned, unsigned> curMove;
        std::vector<std::pair<unsigned, unsigned>> legalMoves = getLegalMoves(board);
        for (unsigned i = 0; i < legalMoves.size(); ++i) {
            curMove = legalMoves[i];
            board[curMove.first][curMove.second] = marker;
            if (marker == PROGRAM) {
                score = minimaxAlgorithm(board, PLAYER, depth + 1, alpha, beta).first;
                if (bestScore < score) {
                    bestMove = curMove;
                    bestScore = score - depth * 10;
                    alpha = std::max(alpha, bestScore);
                    board[curMove.first][curMove.second] = EMPTY;
                    if (beta <= alpha)
                        break;
                }
            } else {
                score = minimaxAlgorithm(board, PROGRAM, depth + 1, alpha, beta).first;
                if (bestScore > score) {
                    bestMove = curMove;
                    bestScore = score + depth * 10;
                    beta = std::min(beta, bestScore);
                    board[curMove.first][curMove.second] = EMPTY;
                    if (beta <= alpha)
                        break;
                }
            }
            board[curMove.first][curMove.second] = EMPTY;
        }
        return std::make_pair(bestScore, bestMove);
    }
    static void printPlayerStatus(unsigned status, std::ostream& out = std::cout) {
        out << "PLAYER ";
        switch (status) {
            case LOST:
                out << "LOST" << std::endl;
                break;
            case DREW:
                out << "DREW" << std::endl;
                break;
            case WON:
                out << "WON" << std::endl;
        }
    }
private:
    static std::vector<std::pair<unsigned, unsigned>> getOccupiedPositions(std::array<std::array<char, 3>, 3> board, char marker) {
        std::vector<std::pair<unsigned, unsigned>> occupiedPositions;
        for (unsigned i = 0; i < 3; ++i) {
            for (unsigned j = 0; j < 3; ++j) {
                if (marker == board[i][j])
                    occupiedPositions.emplace_back(std::make_pair(i, j));
            }
        }
        return occupiedPositions;
    }
    static bool hasWon(std::array<std::array<char, 3>, 3> board, char marker) {
        bool hasWon;
        auto occupiedPositions = getOccupiedPositions(board, marker);
        std::vector<std::pair<unsigned, unsigned>> curWinState;
        for (unsigned i = 0; i < winningStates.size(); ++i) {
            hasWon = true;
            curWinState = winningStates[i];
            for (unsigned j = 0; j < 3; ++j) {
                if (std::find(occupiedPositions.begin(), occupiedPositions.end(), curWinState[j]) == occupiedPositions.end()) {
                    hasWon = false;
                    break;
                }
            }
            if (hasWon)
                break;
        }
        return hasWon;
    }
};

int main() {
    unsigned row, column;
    std::array<std::array<char, 3>, 3> board;
    std::fill_n(&board[0][0], 3 * 3, TicTacToe::EMPTY);
    std::pair<unsigned, std::pair<unsigned, unsigned>> programMove;
    while (TicTacToe::getLegalMoves(board).empty() == false && TicTacToe::getBoardState(board, TicTacToe::PROGRAM) == TicTacToe::DREW) {
        std::cout << "Enter row and column: ";
        std::cin >> row >> column;
        std::cout << std::endl;
        if (TicTacToe::isPositionOccupied(board, std::make_pair(row, column))) {
            std::cout << "The position (" << row << ", " << column << ") is occupied" << std::endl << std::endl;
            continue;
        } else {
            board[row][column] = TicTacToe::PLAYER;
        }
        programMove = TicTacToe::minimaxAlgorithm(board, TicTacToe::PROGRAM);
        board[programMove.second.first][programMove.second.second] = TicTacToe::PROGRAM;
        TicTacToe::printBoard(board);
    }
    unsigned playerStatus = TicTacToe::getBoardState(board, TicTacToe::PLAYER);
    TicTacToe::printPlayerStatus(playerStatus);

    return EXIT_SUCCESS;
}