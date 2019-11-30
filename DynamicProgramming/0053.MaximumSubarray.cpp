class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxVal = INT_MIN, curMax = 0;
        for (int i = 0; i != nums.size(); i++) {
            curMax = std::max(curMax, 0) + nums[i];
            maxVal = std::max(maxVal, curMax);
        }
        return maxVal;
    }
};
