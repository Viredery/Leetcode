class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        const int m = board.size(), n = board.front().size();
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (board[i][j] <= 0) {
                    continue;
                }
                for (const auto& [x, y] : steps) {
                    if (i+x < 0 || i+x >= m || j+y < 0 || j+y >= n) {
                        continue;
                    }
                    if (board[i+x][j+y] <= 0) {
                        board[i+x][j+y] -= 1;
                    } else {
                        board[i+x][j+y] += 1;
                    }
                }
            }
        }
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (board[i][j] == -3 || board[i][j] == 3 || board[i][j] == 4) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
private:
    const std::vector<std::pair<int, int>> steps = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
    };
};
