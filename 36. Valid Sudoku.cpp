class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return isValidRows(board) && isValidColumns(board) && isValidBoxes(board);
    }

    vector<int> countDigits = vector<int>(9, 0);

    bool isValidRows(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            refreshCountDigitsArray();
            for (int j = 0; j < 9; ++j) {
                if (board.at(i).at(j) != '.') {
                    ++countDigits[board.at(i).at(j) - '0' - 1];
                }
            }
            if (!isValidDigits()) {
                return false;
            }
        }
        return true;
    }

    bool isValidColumns(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            refreshCountDigitsArray();
            for (int j = 0; j < 9; ++j) {
                if (board.at(j).at(i) != '.') {
                    ++countDigits[board.at(j).at(i) - '0' - 1];
                }
            }
            if (!isValidDigits()) {
                return false;
            }
        }
        return true;
    }

    bool isValidBoxes(vector<vector<char>>& board) {
        for (int k = 0; k < 9; ++k) {
            refreshCountDigitsArray();
            for (int i = k / 3 * 3; i < (k / 3 + 1) * 3; ++i) {
                for (int j = (k % 3) * 3; j < ((k % 3) + 1) * 3; ++j) {
                    if (board.at(i).at(j) != '.') {
                        ++countDigits[board.at(i).at(j) - '0' - 1];
                    }
                }
            }
            if (!isValidDigits()) {
                return false;
            }
        }
        return true;
    }

    void refreshCountDigitsArray() {
        for (int & countDigit : countDigits) {
            countDigit = 0;
        }
    }

    bool isValidDigits() {
        for (int countDigit : countDigits) {
            if (countDigit > 1) {
                return false;
            }
        }
        return true;
    }
};
