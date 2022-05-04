class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        std::set<long> window;
        for (int i = 0; i != nums.size(); ++i) {
            if (window.size() > k) {
                window.erase(nums[i - k - 1]);
            }
            const long num = static_cast<long>(nums[i]);
            std::set<long>::iterator iter = window.lower_bound(num);
            if (iter != window.end() && *iter <= t + num) {
                return true;
            }
            if (iter != window.begin() && num <= t + *(--iter)) {
                return true;
            }
            window.insert(num);
        }
        return false;
    }
};
