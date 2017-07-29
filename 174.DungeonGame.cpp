class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> minHP(m, vector<int>(n, 0));
        minHP[m-1][n-1] = dungeon[m-1][n-1] > 0 ? 1 : abs(dungeon[m-1][n-1]) + 1;
        for (int j = n-2; j >= 0; j--)
            minHP[m-1][j] = dungeon[m-1][j] - minHP[m-1][j+1] >= 0 ? 1 : minHP[m-1][j+1] - dungeon[m-1][j]);
        for (int i = m-2; i >= 0; i--)
            minHP[i][n-1] = dungeon[i][n-1] - minHP[i+1][n-1] >= 0 ? 1 : minHP[i+1][n-1] - dungeon[i][n-1]);   
        for (int i = m-2; i >= 0; i--)
            for (int j = n-2; j >= 0; j--) {
                int right = dungeon[i][j] - minHP[i][j+1] >= 0 ? 1 : minHP[i][j+1] - dungeon[i][j];
                int down = dungeon[i][j] - minHP[i+1][j] >= 0 ? 1 : minHP[i+1][j] - dungeon[i][j];
                minHP[i][j] = min(right, down);
            }
        return minHP[0][0];
    }
};