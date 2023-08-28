class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        std::vector<int> dp(nums.size(), 0);
        std::deque<int> decreased;
        for (int i = 0; i != nums.size(); ++i) {
            dp[i] = nums[i] + (decreased.empty() ? 0 : dp[decreased.front()]);
            while (!decreased.empty() && i - decreased.front() > k - 1) {
                decreased.pop_front();
            }
            while (!decreased.empty() && dp[decreased.back()] <= dp[i]) {
                decreased.pop_back();
            }
            decreased.push_back(i);
        }
        return dp[nums.size() - 1];
    }
};
