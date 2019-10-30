class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 1)); // [length, count]
        int res = 0, maxlen = 0;
        for (int i = 0; i != nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j])
                    continue;
                if (dp[i][0] == dp[j][0] + 1)
                    dp[i][1] += dp[j][1];
                if (dp[i][0] < dp[j][0] + 1)
                    dp[i] = {dp[j][0] + 1, dp[j][1]};
                
            }
            if (dp[i][0] == maxlen)
                res += dp[i][1];
            if (dp[i][0] > maxlen) {
                maxlen = dp[i][0];
                res = dp[i][1];
            }
        }
        return res;
    }
};
