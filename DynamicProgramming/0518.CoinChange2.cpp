class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int i = 0; i != coins.size(); i++) {
            for (int j = 0; j + coins[i] <= amount; j++)
                dp[j+coins[i]] += dp[j];
        }
        return dp[amount];
    }
};
