class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) {
            return 0;
        }
        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));
        dp[0][1] = -prices[0] - fee;
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);
        }
        return dp[prices.size() - 1][0];
    }
};
