class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> curLongest(s.size(), 0);
        int maxLen = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '(')
                continue;
            if (s[i-1] == '(')
                curLongest[i] = (i - 2 > 0 ? curLongest[i-2] : 0) + 2;
            else if (i - curLongest[i-1] > 0 && s[i - curLongest[i-1] - 1] == '(')
                curLongest[i] = curLongest[i-1] + (i - curLongest[i-1] >= 2 ? curLongest[i - curLongest[i-1] - 2] : 0) + 2;
            maxLen = max(maxLen, curLongest[i]);
        }
        return maxLen;
    }
};
