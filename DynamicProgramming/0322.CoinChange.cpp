class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> min_counts(amount + 1, amount + 1);
        min_counts[0] = 0;
        for (const auto& coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                min_counts[i] = std::min(min_counts[i], min_counts[i - coin] + 1);
            }
        }
        return min_counts[amount] > amount ? -1 : min_counts[amount];
    }
};
