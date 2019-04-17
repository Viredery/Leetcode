class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i != nums.size(); i++) {
            auto iter = hash.find(nums[i]);
            if (iter != hash.end())
                return {iter->second, i};
            hash[target - nums[i]] = i;
        }
        return {};
    }
};
