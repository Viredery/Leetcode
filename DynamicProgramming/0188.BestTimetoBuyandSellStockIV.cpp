class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0 || prices.empty()) {
            return 0;
        }
        std::vector<std::vector<int>> max_profits(prices.size(), std::vector<int>(k + 1, 0));
        std::vector<int> max_prices(k + 1, -prices[0]);
        for (int i = 1; i != prices.size(); ++i) {
            for (int j = 1; j != k + 1; ++j) {
                max_prices[j] = std::max(max_prices[j], max_profits[i][j-1] - prices[i]);
                max_profits[i][j] = std::max(max_profits[i-1][j], prices[i] + max_prices[j]);
            }
        }
        return max_profits[prices.size() - 1][k];
    }
};
