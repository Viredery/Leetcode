class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        vector<vector<int>> dp(3, vector<int>(prices.size(), 0)); // buy, cooldown, sell
        dp[0][0] = -prices[0];
        for (int i = 1; i != prices.size(); i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] - prices[i]);
            dp[1][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1]));
            dp[2][i] = max(dp[0][i - 1] + prices[i], dp[2][i-1]);
        }
        return max(dp[0][prices.size() - 1], max(dp[1][prices.size() - 1], dp[2][prices.size() - 1]));
    }
};