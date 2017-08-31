class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        int start = 0, end = 0;
        int minLen = INT_MAX;
        int subArraySum = nums[0];
        while (start != nums.size() && end != nums.size()) {
            if (subArraySum < s)
                end++;
            if (end != nums.size()) {
                subArraySum += nums[end];
            }
            while (start != nums.size() && subArraySum >= s) {
                minLen = min(minLen, end-start+1);
                if (start == end)
                    return minLen;
                subArraySum -= nums[start++];
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};