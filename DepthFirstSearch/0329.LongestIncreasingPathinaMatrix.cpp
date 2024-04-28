class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix.front().empty()) {
            return 0;
        }
        const int num_rows = matrix.size();
        const int num_columns = matrix.front().size();
        std::vector<std::vector<int>> memo(num_rows, std::vector<int>(num_columns, 0));
        int num_longest_path = 0;
        for (int i = 0; i != num_rows; ++i) {
            for (int j = 0; j != num_columns; ++j) {
                num_longest_path = std::max(num_longest_path, 
                                            DepthFirstSearch(matrix, i, j, &memo));
            }
        }
        return num_longest_path;
    }

private:
    static constexpr std::array<std::pair<int, int>, 4> kDirections = {
        std::make_pair(-1, 0), std::make_pair(0, -1), std::make_pair(1, 0), std::make_pair(0, 1)
    };
    int DepthFirstSearch(const vector<vector<int>>& matrix, 
                         int i, 
                         int j, 
                         std::vector<std::vector<int>>* memo) {
        if ((*memo)[i][j] != 0) {
            return (*memo)[i][j];
        }
        const int num_rows = matrix.size();
        const int num_columns = matrix.front().size();

        (*memo)[i][j] = 1;
        for (const auto& [dx, dy] : kDirections) {
            const int x = i + dx;
            const int y = j + dy;
            if (x < 0 || x >= num_rows || y < 0 || y >= num_columns) {
                continue;
            }
            if (matrix[x][y] <= matrix[i][j]) {
                continue;
            }
            (*memo)[i][j] = std::max((*memo)[i][j], 1 + DepthFirstSearch(matrix, x, y, memo));
        }
        return (*memo)[i][j];

    }
};
