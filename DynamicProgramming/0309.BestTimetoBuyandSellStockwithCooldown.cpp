class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        std::vector<std::vector<std::vector<int>>> dp(
            prices.size(), std::vector<std::vector<int>>(3, std::vector<int>(2, 0)));
        dp[0][1][1] = -prices[0];
        dp[0][2][1] = -prices[0];
        for (int i = 1; i != prices.size(); ++i) {
            for (int j = 1; j <= 2; ++j) {
                dp[i][j][0] = std::max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = std::max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[prices.size() - 1][2][0];
    }
};
