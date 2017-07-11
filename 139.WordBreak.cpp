class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> canBreak(s.size() + 1, false);
        canBreak[0] = true;
        for (int i = 0; i != s.size(); i++)
            for (int j = i; j >= 0; j--)
                if (canBreak[j])
                    if (find(wordDict.begin(), wordDict.end(), s.substr(j, i-j+1)) != wordDict.end())
                        canBreak[i+1] = true;
        return canBreak.back();
    }
};