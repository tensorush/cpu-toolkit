/*
    Sudoku
    ------
*/
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <array>

class Sudoku {
public:
    static void initialize() {
        unsigned row, row_2;
        std::array<unsigned, 3> index;
        for (unsigned i = 0; i < 9; ++i) {
            for (unsigned j = 0; j < 9; ++j) {
                row = i * 9 + j;
                index = { i, 9 + j, 18 + (i / 3) * 3 + j / 3 };
                for (unsigned k = 0; k < 3; ++k) {
                    _group[index[k]].emplace_back(row);
                    _groupsOf[row].emplace_back(index[k]);
                }
            }
        }
        for (unsigned row = 0; row < _neighbours.size(); ++row) {
            for (unsigned index = 0; index < _groupsOf[row].size(); ++index) {
                for (unsigned j = 0; j < 9; ++j) {
                    row_2 = _group[_groupsOf[row][index]][j];
                    if (row_2 != row)
                        _neighbours[row].emplace_back(row_2);
                }
            }
        }
    }
    Sudoku(std::string string) : _cells(81) {
        unsigned row = 0;
        for (unsigned i = 0; i < string.size(); ++i) {
            if (string[i] >= '1' && string[i] <= '9') {
                if (_assign(row, string[i] - '0') == false) {
                    std::cerr << "Assignment failed" << std::endl;
                    return;
                }
                ++row;
            } else if (string[i] == '0' || string[i] == '.') {
                ++row;
            }
        }
    }
    void print(std::ostream& out = std::cout) const {
        unsigned width = 1;
        for (unsigned row = 0; row < _cells.size(); ++row) {
            width = std::max(width, 1 + _cells[row].count());
        }
        std::string side(3 * width, '-');
        for (unsigned i = 0; i < 9; ++i) {
            if (i == 3 || i == 6)
                out << side << "+-" << side << '+' << side << std::endl;
            for (unsigned j = 0; j < 9; ++j) {
                if (j == 3 || j == 6)
                    out << "| ";
                out << _cells[i * 9 + j].toString(width);
            }
            out << std::endl;
        }
    }
    static std::unique_ptr<Sudoku> solve(std::unique_ptr<Sudoku> sudoku) {
        if (sudoku == nullptr || sudoku->_isSolved()) {
            return sudoku;
        }
        unsigned minRowCount = sudoku->_minRowCount();
        Cell cell = sudoku->_getCell(minRowCount);
        for (unsigned i = 1; i <= 9; ++i) {
            if (cell.isVacant(i)) {
                std::unique_ptr<Sudoku> sudoku_2 = std::make_unique<Sudoku>(*sudoku);
                if (sudoku_2->_assign(minRowCount, i)) {
                    std::unique_ptr<Sudoku> sudoku_3 = solve(std::move(sudoku_2));
                    if (sudoku_3)
                        return sudoku_3;
                }
            }
        }
        return nullptr;
    }
private:
    static std::vector<std::vector<unsigned>> _group, _neighbours, _groupsOf;
    class Cell {
    public:
        Cell() : _isVacantValue(9, true) {}
        bool isVacant(unsigned i) const {
            return _isVacantValue[i - 1];
        }
        void eliminate(unsigned i) {
            _isVacantValue[i - 1] = false;
        }
        unsigned count() const {
            return std::count(_isVacantValue.begin(), _isVacantValue.end(), true);
        }
        unsigned value() const {
            auto it = std::find(_isVacantValue.begin(), _isVacantValue.end(), true);
            return (it != _isVacantValue.end()) ? (1 + (it - _isVacantValue.begin())) : (-1);
        }
        std::string toString(unsigned width) const {
            std::string string(width, ' ');
            for (unsigned i = 1, row = 0; i <= 9; ++i) {
                if (isVacant(i))
                    string[row++] = '0' + i;
            }
            return string;
        }
    private:
        std::vector<bool> _isVacantValue;
        friend class Sudoku;
    };
    std::vector<Cell> _cells;
    bool _isSolved() const {
        for (unsigned row = 0; row < _cells.size(); ++row) {
            if (_cells[row].count() != 1)
                return false;
        }
        return true;
    }
    unsigned _minRowCount() const {
        unsigned minCount;
        int minRowCount = -1;
        for (int row = 0; row < _cells.size(); ++row) {
            unsigned curCount = _cells[row].count();
            if (curCount > 1 && (curCount < minCount || minRowCount == -1)) {
                minCount = curCount;
                minRowCount = row;
            }
        }
        return minRowCount;
    }
    Cell _getCell(unsigned row) const {
        return _cells[row];
    }
    bool _assign(unsigned row, unsigned value) {
        for (unsigned i = 1; i <= 9; ++i) {
            if (i != value) {
                if (_eliminate(row, i) == false)
                    return false;
            }
        }
        return true;
    }
    bool _eliminate(unsigned row, unsigned value) {
        if (_cells[row].isVacant(value) == false)
            return true;
        _cells[row].eliminate(value);
        unsigned numVacantCells = _cells[row].count();
        if (numVacantCells == 0) {
            return false;
        } else if (numVacantCells == 1) {
            unsigned value = _cells[row].value();
            for (unsigned i = 0; i < _neighbours[row].size(); ++i) {
                if (_eliminate(_neighbours[row][i], value) == false)
                    return false;
            }
        }
        for (unsigned i = 0; i < _groupsOf[row].size(); ++i) {
            numVacantCells = 0;
            unsigned curRow, vacantRow, index = _groupsOf[row][i];
            for (unsigned j = 0; j < 9; ++j) {
                curRow = _group[index][j];
                if (_cells[curRow].isVacant(value)) {
                    vacantRow = curRow;
                    ++numVacantCells;
                }
            }
            if (numVacantCells == 0) {
                return false;
            } else if (numVacantCells == 1) {
                if (_assign(vacantRow, value) == false)
                    return false;
            }
        }
        return true;
    }
};

std::vector<std::vector<unsigned>> Sudoku::_group(27), Sudoku::_neighbours(81), Sudoku::_groupsOf(81);

int main() {
    Sudoku::initialize();
    std::string rows = "8..........36......7..9.2...5...7.......457.....1...3...1....68..85...1..9....4..";
    std::unique_ptr<Sudoku> sudoku = std::make_unique<Sudoku>(rows);
    std::unique_ptr<Sudoku> solvedSudoku = Sudoku::solve(std::move(sudoku));
    if (solvedSudoku) {
        solvedSudoku->print();
    } else {
        std::cout << "No solution" << std::endl;
    }

    return EXIT_SUCCESS;
}