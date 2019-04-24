class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> threeSumVec;
        std::sort(nums.begin(), nums.end());
        int i = 0;
        while (i + 2 < nums.size()) {
            twoSum(nums, i++, threeSumVec);
            while (i < nums.size() - 2 && nums[i] == nums[i-1])
                i++;
        }
        return threeSumVec;
    }
private:
    void twoSum(vector<int>& nums, int i, vector<vector<int>>& threeSumVec) {
        int target = -nums[i];
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                while (left + 1 <= right && nums[left+1] == nums[left])
                    left++;
                while (right - 1 >= left && nums[right-1] == nums[right])
                    right--;
                threeSumVec.push_back({nums[i], nums[left++], nums[right--]});
            } else if (sum > target)
                right--;
            else
                left++;
        }
    }
};
