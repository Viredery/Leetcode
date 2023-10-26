class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int prefix_max_sum = 0; 
        int prefix_min_sum = 0; 
        int max_sum = std::numeric_limits<int>::min();
        int min_sum = std::numeric_limits<int>::max();
        for (const auto& num : nums) {
            prefix_max_sum = std::max(num, num + prefix_max_sum);
            prefix_min_sum = std::min(num, num + prefix_min_sum);
            max_sum = std::max(max_sum, prefix_max_sum);
            min_sum = std::min(min_sum, prefix_min_sum);
        }

        const int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum == min_sum) {
            return max_sum;
        }
        
        return std::max(max_sum, sum - min_sum);
    }
};
