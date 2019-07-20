class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mapped;
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.size(); i++) {
            if (mapped.find(s[i]) != mapped.end() && mapped[s[i]] >= start)
                start = mapped[s[i]];
            mapped[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
