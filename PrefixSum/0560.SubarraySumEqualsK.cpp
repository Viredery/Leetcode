class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::vector<int> prefix_sums(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            prefix_sums[i] += prefix_sums[i - 1];
        }
        int total_num = 0;
        std::unordered_map<int, int> counts;
        counts[0] = 1;
        for (const auto& prefix_sum : prefix_sums) {
            if (counts.count(prefix_sum - k)) {
                total_num += counts[prefix_sum - k];
            }
            counts[prefix_sum] += 1;
        }
        return total_num;
    }
};
