class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i != s.size(); i++)
            dp[i][i] = true;
        int cnt = s.size();
        for (int i = s.size() - 2; i >= 0; i--)
            for (int j = i + 1; j < s.size(); j++)
                if (s[i] == s[j] && (dp[i+1][j-1] || i + 1 == j)) {
                    dp[i][j] = true;
                    cnt++;
                }
        return cnt;
    }
};
