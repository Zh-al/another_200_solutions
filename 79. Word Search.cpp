class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) {
            return true;
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> visited(board.size(), vector<bool>(board[i].size(), false));
                    if (existHelper(board, word.substr(1, word.size() - 1), visited, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool existHelper(const vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int i, int j) {
        if (word.size() == 0) {
            return true;
        }
        visited[i][j] = true;
        if (i > 0 && !visited[i - 1][j] && board[i - 1][j] == word[0]) {
            if (existHelper(board, word.substr(1, word.size() - 1), visited, i - 1, j)) {
                return true;
            }
        } 
        if (i < board.size() - 1 && !visited[i + 1][j] && board[i + 1][j] == word[0]) {
            if (existHelper(board, word.substr(1, word.size() - 1), visited, i + 1, j)) {
                return true;
            }
        }
        if (j > 0 && !visited[i][j - 1] && board[i][j - 1] == word[0]) {
            if (existHelper(board, word.substr(1, word.size() - 1), visited, i, j - 1)) {
                return true;
            }
        }
         if (j < board[i].size() - 1 && !visited[i][j + 1] && board[i][j + 1] == word[0]) {
            if (existHelper(board, word.substr(1, word.size() - 1), visited, i, j + 1)) {
                return true;
            }
        }
        visited[i][j] = false;
        return false;
    }
};
