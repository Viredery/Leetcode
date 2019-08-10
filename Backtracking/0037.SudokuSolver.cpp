class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0, 0);
    }
private:
    bool solveSudoku(vector<vector<char>>& board, int y, int x) {
        if (y == board.size())
            return true;
        if (x == board.size())
            return solveSudoku(board, y+1, 0);
        if (board[y][x] != '.')
            return solveSudoku(board, y, x+1);
        
        for (char c = '1'; c <= '9'; c++) {
            if (isValidPosition(board, y, x, c)) {
                board[y][x] = c;
                if (solveSudoku(board, y, x+1))
                    return true;
                board[y][x] = '.';
            }   
        }
        return false;     
    }
    
    bool isValidPosition(vector<vector<char>>& board, int y, int x, char c) {
        int cellY = y / 3 * 3, cellX = x / 3 * 3;
        for (int i = 0; i <= 8; i++) {
            if (board[y][i] == c || board[i][x] == c ||
                    board[cellY + i/3][cellX + i%3] == c)
                return false;
        }
        return true;
    }
};
