class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0' && (s[i-1] == '0' || s[i-1] >= '3'))
                return 0;
            else if (s[i] == '0')
                dp[i+1] = dp[i-1];
            else if ((s[i] <= '6' && s[i-1] == '2') || (s[i-1] == '1'))
                dp[i+1] = dp[i] + dp[i-1];
            else
                dp[i+1] = dp[i];
        }
        return dp[s.size()];
    }
};
