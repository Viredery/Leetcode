class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> arr(nums.size() + 2, 1);
        for (int i = 0; i != nums.size(); i++)
            arr[i + 1] = nums[i];
        
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
        for (int k = 1; k <= nums.size(); k++) {
            for (int left = 1; left <= nums.size() - k + 1; left++) {
                int right = left + k - 1;
                for (int i = left; i <= right; i++)
                    dp[left][right] = max(dp[left][right],
                                          dp[left][i-1] + dp[i+1][right] + arr[left-1] * arr[i] * arr[right + 1]);
            }
        }
        return dp[1][nums.size()];
    }
};
