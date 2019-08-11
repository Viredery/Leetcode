class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> dict;
        for (auto str : strs) {
            string tmp(str);
            sort(tmp.begin(), tmp.end());
            if (dict.find(tmp) == dict.end())
                dict[tmp] = {str};
            else
                dict[tmp].push_back(str);
        }
        for (auto iter = dict.begin(); iter != dict.end(); iter++)
            res.push_back(move(iter->second));
        return res;
    }
};
