class Solution {
public:
    int countSubstrings(string s) {
        std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));
        int num_substrings = 0;
        for (int length = 1; length <= dp.size(); ++length) {
            for (int i = 0; i + length <= dp.size(); ++i) {
                const bool is_palindrome_before = length <= 2 ? true : dp[i + 1][i + length - 2];
                dp[i][i + length - 1] = is_palindrome_before && s[i] == s[i + length - 1];
                if (dp[i][i + length - 1]) {
                    ++num_substrings;
                }
            }
        }
        return num_substrings;
    }
};
