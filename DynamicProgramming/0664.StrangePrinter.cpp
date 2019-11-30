class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty())
            return 0;
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int i = 0; i != n; i++)
            dp[i][i] = 1;
        for (int len = 2; len <= n; len++)
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;
                dp[l][r] = dp[l+1][r] + dp[l][l];
                for (int i = l+1; i <= r; i++)
                    if (s[i] == s[l])
                        dp[l][r] = std::min(dp[l][r], dp[l][i-1] + dp[i+1][r]);
            }
        return dp[0][n-1];
    }
};
