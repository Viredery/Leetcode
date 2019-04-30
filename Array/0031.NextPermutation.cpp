class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) return;
        int start = nums.size() - 2;
        while (start >= 0 && nums[start] >= nums[start + 1])
            start--; 
        if (start >= 0) {
            int end = nums.size() - 1;
            while (end > start && nums[end] <= nums[start])
                end--;
            std::swap(nums[start], nums[end]);
        }
        std::reverse(nums.begin() + start + 1, nums.end());
    }
};
