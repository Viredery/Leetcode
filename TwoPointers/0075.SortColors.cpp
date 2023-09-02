class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        int left = 0;
        int right = nums.size() - 1;
        for (int i = 0; i <= right; ++i) {
            if (nums[i] == 0) {
                std:swap(nums[left++], nums[i]);
            } else if (nums[i] == 2) {
                std::swap(nums[right--], nums[i--]);
            }
        }
    }
};
