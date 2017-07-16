class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        for (int i = 0; i < s.size() - 1; i++) {
            if (find(wordDict.begin(), wordDict.end(), s.substr(0, i+1)) == wordDict.end())
                continue;
            vector<string> strs = sentences.count(s.substr(i+1)) ? 
                     sentences[s.substr(i+1)] : wordBreak(s.substr(i+1), wordDict);
            if (strs.empty())
                continue;
            for (auto str : strs)
                res.push_back(s.substr(0, i+1) + " " + str);
        }
        if (find(wordDict.begin(), wordDict.end(), s) != wordDict.end())
            res.push_back(s);
        sentences[s] = res;
        return res;
    }
private:
    unordered_map<string, vector<string>> sentences;
};