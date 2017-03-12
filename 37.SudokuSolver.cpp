class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0, 0);
    }
    bool check(vector<vector<char>> &board, int x, int y, char val) {
        int row = x - x % 3, col = y - y % 3;
        for (int i = 0; i != 9; i++)
            if (board[x][i] == val || board[i][y] == val || board[row + i / 3][col + i % 3] == val)
                return false;
        return true;
    }
    bool solveSudoku(vector<vector<char>>& board, int x, int y) {
        if(x == 9)
            return true;
        if(y == 9)
            return solveSudoku(board, x + 1, 0);
        if (board[x][y] != '.')
            return solveSudoku(board, x, y + 1);
        for (char val = '1'; val <= '9'; val++)
            if(true == check(board, x, y, val)) {
                board[x][y] = val;
                if (true == solveSudoku(board, x, y + 1))
                    return true;
                board[x][y] = '.';
            }
        return false;
    }
};