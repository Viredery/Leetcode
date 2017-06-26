class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestNum = 0;
        unordered_map<int, int> numMap;
        for (auto num : nums) {
            if (numMap[num])
                continue;
            int left = numMap[num - 1];
            int right = numMap[num + 1];
            numMap[num] = numMap[num - left] = numMap[num + right] = left + right + 1;
            longestNum = max(longestNum, numMap[num]);
        }
        return longestNum;
    }
};