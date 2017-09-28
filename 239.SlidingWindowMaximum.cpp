class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> maximum_positions;
        int i = 0;
        while (i < k) {
            while (!maximum_positions.empty() && nums[maximum_positions.back()] < nums[i])
                maximum_positions.pop_back();
            maximum_positions.push_back(i++);
        }
        if (maximum_positions.empty())
            return res;
        res.push_back(nums[maximum_positions.front()]);
        while (i < nums.size()) {
            if (maximum_positions.front() == i - k)
                maximum_positions.pop_front();
            while (!maximum_positions.empty() && nums[maximum_positions.back()] < nums[i])
                maximum_positions.pop_back();
            maximum_positions.push_back(i++);
            res.push_back(nums[maximum_positions.front()]);
        }
        return res;
    }
};