class Solution {
public:
    int minCut(string s) {
        vector<int> dp(s.size(), 0);
        for (int i = 0; i != s.size(); i++)
            dp[i] = i;
        
        for (int i = 0; i != s.size(); i++) {
            for (int j = 0; i-j >= 0 && i+j < s.size() && s[i-j] == s[i+j]; j++)
                dp[i+j] = min(dp[i+j], i-j == 0 ? 0 : dp[i-j-1]+1);

            for (int j = 1; i-j+1 >= 0 && i+j < s.size() && s[i-j+1] == s[i+j]; j++)
                dp[i+j] = min(dp[i+j], i-j+1 == 0 ? 0 : dp[i-j]+1);
        }
        return dp.back();
    }
};
