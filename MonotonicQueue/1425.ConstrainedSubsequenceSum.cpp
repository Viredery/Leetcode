class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        std::vector<int> sums(nums.size(), 0);
        std::deque<int> decreased;
        int max_sum = std::numeric_limits<int>::min();
        for (int i = 0; i != nums.size(); ++i) {
            sums[i] = nums[i];
            if (!decreased.empty()) {
                sums[i] += sums[decreased.front()];
            }
            max_sum = std::max(max_sum, sums[i]);
            while (!decreased.empty() && i - decreased.front() >= k) {
                decreased.pop_front();
            }
            while (!decreased.empty() && sums[i] >= sums[decreased.back()]) {
                decreased.pop_back();
            }
            if (sums[i] > 0) {
                decreased.push_back(i);
            }
        }
        return max_sum;
    }
};
