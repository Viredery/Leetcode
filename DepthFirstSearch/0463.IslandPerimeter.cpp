class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid.front().size();
        int num_perimeter = 0;
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                num_perimeter += 4;
                if (i < m - 1 && grid[i + 1][j] == 1) {
                    num_perimeter -= 2;
                }
                if (j < n - 1 && grid[i][j + 1] == 1) {
                    num_perimeter -= 2;
                }
            }
        }
        return num_perimeter;
    }
};
