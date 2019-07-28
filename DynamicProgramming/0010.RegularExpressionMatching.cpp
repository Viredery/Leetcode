class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));
        dp[s.size()][p.size()] = 1;
        
        for (int i = s.size(); i >= 0; i--)
            for (int j = p.size() - 1; j >= 0; j--) {
                bool cur_match = (i < s.length() &&
                                    (p[j] == s[i] || p[j] == '.'));
                if (j + 1 < p.size() && p[j+1] == '*')
                    dp[i][j] = dp[i][j+2] || (cur_match && dp[i+1][j]);
                else
                    dp[i][j] = cur_match && dp[i+1][j+1];
            }
        return dp[0][0];
    }
};
