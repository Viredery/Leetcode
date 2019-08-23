class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        int length = s1.size();
        bool dp[length][length][length+1];
        for (int k = 1; k <= length; k++)
            for (int i = 0; i + k <= length; i++)
                for (int j = 0; j + k <= length; j++) {
                    if (k == 1)
                        dp[i][j][k] = s1[i] == s2[j];
                    else {
                        dp[i][j][k] = false;
                        for (int q = 1; q < k && !dp[i][j][k]; q++)
                            dp[i][j][k] = (dp[i][j][q] && dp[i+q][j+q][k-q]) || (dp[i][j+k-q][q] && dp[i+q][j][k-q]);
                    }
                }
        return dp[0][0][length];
    }
};
