class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_map<char, char> s_dict;
        std::unordered_map<char, char> t_dict;
        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 0; i != s.size(); ++i) {
            if (!s_dict.count(s[i]) && !t_dict.count(t[i])) {
                s_dict[s[i]] = t[i];
                t_dict[t[i]] = s[i];
                continue;
            }
            if ((s_dict.count(s[i]) && s_dict[s[i]] != t[i]) ||
                (t_dict.count(t[i]) && t_dict[t[i]] != s[i])) {
                return false;
            }
        }
        return true;
    }
};
