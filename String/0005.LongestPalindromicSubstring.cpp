class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 0;
        for (int i = 0; i != s.size(); i++) {
            int len1 = longestPalindrome(s, i, i);
            int len2 = longestPalindrome(s, i, i+1);
            int len = max(len1, len2);
            if (len > maxLen) {
                start = i - (len-1) / 2;
                maxLen = len;
            }
        }
        return s.substr(start, maxLen);
    }
private:
    int longestPalindrome(string& s, int idx1, int idx2) {
        while (idx1 >= 0 && idx2 < s.size() && s[idx1] == s[idx2]) {
            idx1--; idx2++;
        }
        return idx2 - idx1 - 1;
    }
};
