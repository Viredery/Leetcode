class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int median = (left + right) / 2;
            if (nums[median] == target)
                return median;
            else if (nums[median] < target)
                left = median + 1;
            else
                right = median;
        }
        return nums[right] >= target ? right : right + 1;
    }
};