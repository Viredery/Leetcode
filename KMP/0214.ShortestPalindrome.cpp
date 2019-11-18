class Solution {
public:
    string shortestPalindrome(string s) {
        string rev(s);
        std::reverse(rev.begin(), rev.end());      
        string sNew = s + "#" + rev;
        vector<int> kmp(sNew.size(), 0);

        for (int i = 1, j = 0; i != kmp.size(); i++) {
            while (j && sNew[i] != sNew[j])
                j = kmp[j-1];
            if (sNew[i] == sNew[j])
                j++;
            kmp[i] = j;
        }
        return rev.substr(0, s.size() - kmp.back()) + s;
    }
};
