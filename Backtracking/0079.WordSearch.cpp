class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i != m; i++)
            for (int j = 0; j != n; j++)
                if (search(board, i, j, word, 0))
                    return true;
        return false;
    }
    
private:
    bool search(vector<vector<char>>& board, int i, int j, string& word, int k) {
        int m = board.size(), n = board[0].size();
        if (board[i][j] != word[k])
            return false;
        if (k == word.size() - 1)
            return true;
        int tmp = board[i][j];
        board[i][j] = char(0);
        if (i - 1 >= 0 && search(board, i-1, j, word, k+1))
            return true;
        if (j - 1 >= 0 && search(board, i, j-1, word, k+1))
            return true;
        if (i + 1 < m && search(board, i+1, j, word, k+1))
            return true;
        if (j + 1 < n && search(board, i, j+1, word, k+1))
            return true;
        board[i][j] = tmp;
        return false;
    }
};
