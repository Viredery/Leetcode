class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0;
        std::deque<int> increased, decreased;
        int max_size = 0;
        for (int right = 0; right != nums.size(); ++right) {
            while (!decreased.empty() && nums[decreased.back()] <= nums[right]) {
                decreased.pop_back();
            }
            while (!increased.empty() && nums[increased.back()] >= nums[right]) {
                increased.pop_back();
            }
            increased.push_back(right);
            decreased.push_back(right);

            while (nums[decreased.front()] - nums[increased.front()] > limit) {
                ++left;
                while (decreased.front() < left) {
                    decreased.pop_front();
                }
                while (increased.front() < left) {
                    increased.pop_front();
                }
            }
            max_size = std::max(max_size, right - left + 1);
        }
        return max_size;
    }
};
