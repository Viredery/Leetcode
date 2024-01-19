class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[i].size(); ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                max_area = std::max(max_area, dfs(grid, i, j));
            }
        }
        return max_area;
    }
private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        const int m = grid.size();
        const int n = grid.front().size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
    }
};
