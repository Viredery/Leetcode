class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> decreased;
        for (int r = 0; r != k; ++r) {
            while (!decreased.empty() && decreased.back() < nums[r]) {
                decreased.pop_back();
            }
            decreased.push_back(nums[r]);
        }
        std::vector<int> window_maximum = {decreased.front()};
        for (int r = k; r != nums.size(); ++r) {
            if (nums[r - k] == decreased.front()) {
                decreased.pop_front();
            }
            while (!decreased.empty() && decreased.back() < nums[r]) {
                decreased.pop_back();
            }
            decreased.push_back(nums[r]);
            window_maximum.push_back(decreased.front());
        }
        return window_maximum;
    }
};
