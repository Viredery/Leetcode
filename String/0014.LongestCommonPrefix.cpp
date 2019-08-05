class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string predix;
        for (int i = 0; i != strs[0].size(); i++) {
            char common = strs[0][i];
            for (int j = 1; j != strs.size(); j++) {
                if (strs[j][i] != common)
                    return predix;
            }
            predix += common;
        }
        return predix;
    }
};
