class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int pos = 0;
        while (pos <= right) {
            if (nums[pos] == 0)
                std::swap(nums[pos++], nums[left++]);
            else if (nums[pos] == 2)
                std::swap(nums[pos], nums[right--]);
            else
                pos++;
        }
    }
};
