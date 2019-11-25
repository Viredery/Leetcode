class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
            return "";
        unordered_map<char, int> hash;
        for (char c : t)
            hash[c]++;
        int cnt = t.size();
        
        string res;
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (hash[s[r]] > 0)
                cnt--;
            hash[s[r]]--;
            while (l < s.size() && hash[s[l]] < 0)
                hash[s[l++]]++;
            if (cnt == 0 && (res.empty() || res.size() > r - l + 1))
                res = s.substr(l, r - l + 1);
        }
        return res;   
    }
};
