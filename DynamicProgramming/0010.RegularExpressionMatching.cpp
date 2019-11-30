class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, false));
        dp[m][n] = true;
        
        for (int j = n-1; j >= 0; j -= 2) {
            if (p[j] != '*')
                break;
            dp[m][j-1] = true;
        }
        for (int i = m-1; i >= 0; i--)
            for (int j = n-1; j >= 0; j--) {
                if (p[j] == '*')
                    continue;
                bool match = p[j] == '.' || s[i] == p[j];
                if (j != n-1 && p[j+1] == '*')
                    dp[i][j] = dp[i][j+2] | (match & dp[i+1][j]);
                else
                    dp[i][j] = match & dp[i+1][j+1];
            }
        return dp[0][0];
    }
};
