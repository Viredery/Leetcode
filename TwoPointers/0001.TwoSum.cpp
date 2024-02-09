class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2) {
            return {};
        }
        std::vector<int> indexes(nums.size(), 0);
        std::iota(indexes.begin(), indexes.end(), 0);
        std::ranges::sort(indexes, [&nums](auto& l, auto& r) {
            return nums[l] < nums[r];
        });
        int left = 0;
        int right = indexes.size() - 1;
        while (left <= right) {
            const int sum = nums[indexes[left]] + nums[indexes[right]];
            if (sum == target) {
                return {indexes[left], indexes[right]};
            }
            if (sum > target) {
                --right;
            } else {
                ++left;
            }
        }
        return {};
    }
};
