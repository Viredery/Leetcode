class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= s1.size(); i++) {
            if (s1[i-1] != s3[i-1])
                break;
            dp[i][0] = 1;
        }
        for (int i = 1; i <= s2.size(); i++) {
            if (s2[i-1] != s3[i-1])
                break;
            dp[0][i] = 1;
        }
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1]) ||
                    (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
            }
        }
        return dp[s1.size()][s2.size()] && (s1.size() + s2.size() == s3.size());
    }
};
