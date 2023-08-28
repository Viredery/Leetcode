class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> decreased;
        std::vector<int> max_nums;
        int left_limit = 1 - k;
        for (int i = 0; i != nums.size(); ++i) {
            while (!decreased.empty() && decreased.front() < left_limit) {
                decreased.pop_front();
            }
            while (!decreased.empty() && nums[decreased.back()] <= nums[i]) {
                decreased.pop_back();
            }
            decreased.push_back(i);
            if (left_limit++ >= 0) {
                max_nums.push_back(nums[decreased.front()]);
            }
        }
        return max_nums;
    }
};
