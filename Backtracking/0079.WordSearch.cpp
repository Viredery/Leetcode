class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty())
            return false;
        m = board.size();
        n = board[0].size();
        
        for (int i = 0; i != m; i++)
            for (int j = 0; j != n; j++)
                if (backtracking(board, i, j, word, 0))
                    return true;
        return false;
    }
    
private:
    int m, n;
    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    
    bool backtracking(vector<vector<char>>& board, int i, int j, string& word, int k) {

        if (board[i][j] != word[k])
            return false;
        if (k == word.size() - 1)
            return true;
        
        board[i][j] = '.';
        for (int pos = 0; pos != dx.size(); pos++) {
            int x = i + dx[pos], y = j + dy[pos];
            if (x < 0 || x >= m || y < 0 || y >= n)
                continue;
            if (backtracking(board, x, y, word, k + 1))
                return true;
        }
        board[i][j] = word[k];
        return false;
    }
};
