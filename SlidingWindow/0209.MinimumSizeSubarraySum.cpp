class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int cur_sum = nums[0];
        int min_length = nums.size() + 1;
        int begin = 0, end = 1;
        while (end < nums.size()) {
            while (end < nums.size() && cur_sum < target) {
                cur_sum += nums[end++];
            }
            while (begin < end && cur_sum >= target) {
                min_length = std::min(min_length, end - begin);
                cur_sum -= nums[begin++];
            }
        }
        return min_length > nums.size() ? 0 : min_length;
    }
};
