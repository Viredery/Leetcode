class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        std::vector<int> prefix_sums(nums.begin(), nums.end());
        for (int i = 1; i < prefix_sums.size(); ++i) {
            prefix_sums[i] += prefix_sums[i - 1];
        }
        int num_subarrays = 0;
        std::unordered_map<int, int> counts = {{0, 1}};
        for (const auto& prefix_sum : prefix_sums) {
            const int remainder = (prefix_sum % k + k) % k;
            num_subarrays += counts[remainder];
            counts[remainder] += 1;
        }
        return num_subarrays;
    }
};
