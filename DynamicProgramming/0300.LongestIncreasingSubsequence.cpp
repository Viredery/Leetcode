class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int length = 0;
        for (int i = 0; i != nums.size(); i++) {
            int l = 0, r = length - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (dp[mid] >= nums[i])
                    r = mid;
                else
                    l = mid + 1;
            }
            if (l == length || (l == length - 1 && dp[l] < nums[i]))
                dp[length++] = nums[i];
            else
                dp[l] = nums[i];
        }
        return length;
    }
};
