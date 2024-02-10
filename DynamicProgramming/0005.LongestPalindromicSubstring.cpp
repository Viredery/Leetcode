class Solution {
public:
    string longestPalindrome(string s) {
        std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));
        for (int i = 0; i != dp.size(); ++i) {
            dp[i][i] = true;
            if (i + 1 != dp.size()) {
                dp[i][i + 1] = s[i] == s[i + 1];
            }
        }
        for (int length = 3; length <= dp.size(); ++length) {
            for (int j = 0; j <= dp.size() - length; ++j) {
                dp[j][j + length - 1] = 
                    dp[j + 1][j + length - 2] && s[j] == s[j + length - 1];
            }
        }
        int max_size = 0;
        std::string substring;
        for (int i = 0; i != dp.size(); ++i) {
            for (int j = i; j != dp.size(); ++j) {
                if (dp[i][j] && max_size < j - i + 1) {
                    max_size = j - i + 1;
                    substring = s.substr(i, j - i + 1);
                }
            }
        }
        return substring;
    }
};
