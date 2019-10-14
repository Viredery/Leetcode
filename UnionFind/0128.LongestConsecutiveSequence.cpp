class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int maxLength = 0;
        for (int num : nums) {
            if (cnt[num])
                continue;
            int left = cnt[num - 1];
            int right = cnt[num + 1];
            cnt[num] = cnt[num-left] = cnt[num+right] = left + right + 1;
            maxLength = max(maxLength, cnt[num]);
        }
        return maxLength;
    }
};
