class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        const int amount = sum / 2;
        std::vector<int> dp(amount + 1, false);
        dp[0] = true;
        for (const auto& num : nums) {
            for (int i = amount; i >= 1; --i) {
                if (i - num >= 0) {
                    dp[i] |= dp[i - num];
                }
            }
        }
        return dp[amount];
    }
};
