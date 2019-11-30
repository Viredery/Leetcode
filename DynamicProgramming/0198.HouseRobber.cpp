class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        for (int i = 1; i != n+1; i++) {
            dp[0][i] = std::max(dp[1][i-1], dp[0][i-1]);
            dp[1][i] = dp[0][i-1] + nums[i-1];
        }
        return std::max(dp[0][n], dp[1][n]);
    }
};
