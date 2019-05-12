class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxVal = INT_MIN, curMax = 0;
        for (int num : nums) {
            curMax = curMax > 0 ? curMax + num : num;
            maxVal = std::max(maxVal, curMax);
        }
        return maxVal;
    }
};
