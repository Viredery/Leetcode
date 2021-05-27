class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) {
            return "";
        }
        std::unordered_map<char, int> char_count;
        for (const auto& c : t) {
            char_count[c]++;
        }
        std::string res;
        int cnt = t.size();
        for (int l = 0, r = 0; r != s.size(); ++r) {
            if (char_count[s[r]] > 0) {
                cnt--;
            }
            char_count[s[r]]--;
            while (l < s.size() && char_count[s[l]] < 0) {
                char_count[s[l++]]++;
            }
            if (cnt == 0 && (res.empty() || res.size() > r - l + 1)) {
                res = s.substr(l, r - l + 1);
            }
        }
        return res;
    }
};

