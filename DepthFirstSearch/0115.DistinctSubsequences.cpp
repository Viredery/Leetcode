class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size(), n = s.size();
        vector<vector<long>> dp(m+1, vector<long>(n+1, 0l));
        for (int i = 0; i <= n; i++)
            dp[0][i] = 1l;
        for (int i = 1; i <= m; i++) 
            for (int j = i; j <= n; j++)
                dp[i][j] = dp[i][j-1] + (t[i-1] == s[j-1] ? dp[i-1][j-1] : 0l);
        return static_cast<int>(dp[m][n]);
    }
};
