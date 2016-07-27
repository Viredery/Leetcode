class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i != 9; i++) {
            map<char, bool> rowMap, colMap, squareMap;
            for (int j = 0; j != 9; j++) {
                if ('.' != board[i][j]) {
                    if (rowMap.find(board[i][j]) == rowMap.end())
                        rowMap[board[i][j]] = true;
                    else
                        return false;
                }
                if ('.' != board[j][i]) {
                    if (colMap.find(board[j][i]) == colMap.end())
                        colMap[board[j][i]] = true;
                    else
                        return false;
                }
                if ('.' != board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3]) {
                    if (squareMap.find(board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3]) == squareMap.end())
                        squareMap[board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3]] = true;
                    else
                        return false;
                }
            }
        }
        return true;
    }
};