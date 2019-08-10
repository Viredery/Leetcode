class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        return isValidSudoku(board, 0, 0);
    }

private:
    bool isValidSudoku(vector<vector<char>>& board, int y, int x) {
        if (y == board.size())
            return true;
        if (x == board.size())
            return isValidSudoku(board, y+1, 0);
        if (board[y][x] == '.' || isValidPosition(board, y, x))
            return isValidSudoku(board, y, x+1);
        return false;            
    }
    
    bool isValidPosition(vector<vector<char>>& board, int y, int x) {
        int cellY = y / 3 * 3, cellX = x / 3 * 3;
        for (int i = 0; i != 9; i++) {
            if (board[y][i] == board[y][x] && i != x)
                return false;
            if (board[i][x] == board[y][x] && i != y)
                return false;
            if (board[cellY + i/3][cellX + i%3] == board[y][x] && 
                    cellY + i/3 != y && cellX + i%3 != x)
                return false;
        }
        return true;
    }
};
