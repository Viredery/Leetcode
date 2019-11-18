class Solution {
public:
    string shortestPalindrome(string s) {
        string rev(s);
        std::reverse(rev.begin(), rev.end());      
        string sNew = s + "#" + rev;
        vector<int> pattern(sNew.size(), 0);

        for (int i = 1, j = 0; i != pattern.size(); i++) {
            while (j && sNew[i] != sNew[j])
                j = pattern[j-1];
            if (sNew[i] == sNew[j])
                j++;
            pattern[i] = j;
        }
        return rev.substr(0, s.size() - pattern.back()) + s;
    }
};
