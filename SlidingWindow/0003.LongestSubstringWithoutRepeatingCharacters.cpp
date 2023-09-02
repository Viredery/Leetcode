class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> occurrence;
        int left = 0;
        int max_len = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (occurrence.count(s[i]) && occurrence[s[i]] >= left) {
                left = occurrence[s[i]] + 1;
            }
            occurrence[s[i]] = i;
            max_len = std::max(max_len, i - left + 1);
        }
        return max_len;
    }
};
