class Solution {
public:
    int minCut(string s) {
        vector<int> numCut(s.size(), 0);
        for (int i = 0; i != s.size(); i++)
            numCut[i] = i;
        for (int i = 0; i != s.size(); i++) {
            for (int j = 0; i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]; j++)
                numCut[i + j] = min(numCut[i + j], 1 + (i - j - 1 >= 0 ? numCut[i - j - 1] : -1));
            for (int j = 1; i - j + 1 >= 0 && i + j < s.size() && s[i - j + 1] == s[i + j]; j++)
                numCut[i + j] = min(numCut[i + j], 1 + (i - j >= 0 ? numCut[i - j] : -1));
        }
        return numCut.back();
    }
};