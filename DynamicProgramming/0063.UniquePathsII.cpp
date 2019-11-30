class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long long>> dp(2, vector<long long>(n, 0));
        
        for (int i = 0; i != m; i++)
            for (int j = 0; j != n; j++) {
                dp[i & 1][j] = 0;
                if (obstacleGrid[i][j] == 1)
                    continue;
                if (!i && !j)
                    dp[i & 1][j] = 1;
                if (i > 0)
                    dp[i & 1][j] += dp[i-1 & 1][j];
                if (j > 0)
                    dp[i & 1][j] += dp[i & 1][j-1];
                cout << dp[i & 1][j] << endl;
            }
        return dp[m-1 & 1][n-1];
    }
};
