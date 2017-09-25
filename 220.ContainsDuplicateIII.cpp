class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window;
        for (int i = 0; i != nums.size(); i++) {
            if (i > k)
                window.erase(nums[i-k-1]);
            auto ptr = window.lower_bound(static_cast<long>(nums[i]) - t);
            if (ptr != window.end() && *ptr <= static_cast<long>(nums[i]) + t)
                return true;
            window.insert(nums[i]);
        }
        return false;
    }
};