class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            twoSum(nums, i, i + 1, nums.size() - 1, &res);
        }
        return res;
    }
private:
    void twoSum(const std::vector<int>& nums, 
                int first, 
                int left,
                int right,
                std::vector<std::vector<int>>* res) {
        while (left < right) {
            if (nums[first] + nums[left] + nums[right] == 0) {
                res->push_back(std::vector<int>{nums[first], nums[left++], nums[right--]});
                while (left < right && nums[left] == nums[left - 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right + 1]) {
                    right--;
                }
            } else if (nums[first] + nums[left] + nums[right] < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
};
