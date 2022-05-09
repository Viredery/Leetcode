class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        int start = 0, end = 0;
        while (end < nums.size()) {
            end++;
            long should_be = static_cast<long>(nums[start]) + end - start;
            if (end == nums.size() || static_cast<long>(nums[end]) != should_be) {
                ranges.push_back(GetRange(nums, start, end - 1));
                start = end;
            }
        }
        return ranges;
    }
private:
    std::string GetRange(const vector<int>& nums, int start, int end) {
        if (start == end) {
            return std::to_string(nums[start]);
        }
        return std::to_string(nums[start]) + "->" + std::to_string(nums[end]);
    }
};
