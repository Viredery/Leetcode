class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        std::vector<int> prefix_sums(nums.size());
        for (int i = 0; i != prefix_sums.size(); ++i) {
            prefix_sums[i] = nums[i] == 1 ? nums[i] : -1;
            if (i > 0) {
                prefix_sums[i] += prefix_sums[i - 1];
            }
        }
        int max_length = 0;
        std::unordered_map<int, int> fisrt_prefix_sums = {{0, -1}};
        for (int i = 0; i != prefix_sums.size(); ++i) {
            if (fisrt_prefix_sums.count(prefix_sums[i])) {
                max_length = std::max(max_length, i - fisrt_prefix_sums[prefix_sums[i]]);
                continue;
            }
            fisrt_prefix_sums[prefix_sums[i]] = i;
        }
        return max_length;
    }
};
