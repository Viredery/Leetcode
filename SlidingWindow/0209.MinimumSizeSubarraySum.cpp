class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int current_sum = 0;
        int min_len = std::numeric_limits<int>::max();
        int left = 0;
        for (int i = 0; i != nums.size(); ++i) {
            current_sum += nums[i];
            while (current_sum >= target) {
                min_len = std::min(min_len, i - left + 1);
                current_sum -= nums[left];
                left++;
            }
        }
        return min_len == std::numeric_limits<int>::max() ? 0 : min_len;
    }
};
