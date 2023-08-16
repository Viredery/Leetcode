class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty() || board.front().empty()) {
            return;
        }
        backtracking(board, 0);
    }
private:
    bool backtracking(vector<vector<char>>& board, int pos) const {
        if (pos == board.size() * board.front().size()) {
            return true;
        }
        const int x = pos / board.front().size();
        const int y = pos % board.front().size();
        if (board[x][y] != '.') {
            return backtracking(board, pos + 1);
        }
        for (char c = '1';  c <= '9'; ++c) {
            if (!isValid(board, x, y, c)) {
                continue;
            }
            board[x][y] = c;
            if (backtracking(board, pos + 1)) {
                return true;
            }
            board[x][y] = '.';
        }
        return false;
    }

    bool isValid(vector<vector<char>>& board, int x, int y, char c) const {
        const int start_x = x / 3 * 3;
        const int start_y = y / 3 * 3;
        for (int i = 0; i != 9; ++i) {
            if (board[i][y] == c || board[x][i] == c || 
                board[start_x + i / 3][start_y + i % 3] == c) {
                return false;
            }
        }
        return true;
    }
};
