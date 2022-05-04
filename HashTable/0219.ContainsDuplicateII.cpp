class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int pos = 0;
        std::unordered_set<int> existed;
        while (pos < nums.size() && pos < k) {
            if (existed.count(nums[pos])) {
                return true;
            }
            existed.insert(nums[pos++]);
        }
        while (pos < nums.size()) {
            if (existed.count(nums[pos])) {
                return true;
            }
            existed.insert(nums[pos]);
            existed.erase(nums[pos++ - k]);
        }
        return false;
    }
};
