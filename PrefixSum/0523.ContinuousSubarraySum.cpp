class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        std::vector<int> prefix_sums(nums.begin(), nums.end());
        for (int i = 1; i < prefix_sums.size(); ++i) {
            prefix_sums[i] += prefix_sums[i - 1];
        }
        std::unordered_map<int, int> first_remainders = {{0, -1}};
        for (int i = 0; i != prefix_sums.size(); ++i) {
            const int remainder = prefix_sums[i] % k;
            if (first_remainders.count(remainder)) {
                if (i - first_remainders[remainder] >= 2) {
                    return true;
                }
                continue;
            }
            first_remainders[remainder] = i;
        }
        return false;
    }
};
