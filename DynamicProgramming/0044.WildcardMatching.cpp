class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));
        dp[s.size()][p.size()] = 1;
        
        for (int i = p.size() - 1; i >= 0; i--)
            if (p[i] != '*')
                break;
            else
                dp[s.size()][i] = true;
        
        for (int i = s.size() - 1; i >= 0; i--)
            for (int j = p.size() - 1; j >= 0; j--)
                if (p[j] == '*')
                    dp[i][j] = dp[i][j+1] || dp[i+1][j];
                else if (s[i] == p[j] || p[j] == '?')
                    dp[i][j] = dp[i+1][j+1];
          
        return dp[0][0];
    }
};
