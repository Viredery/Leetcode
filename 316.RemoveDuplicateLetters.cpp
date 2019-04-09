class Solution {
public:
    string removeDuplicateLetters(string s) {
        array<int, 26> counts;
        counts.fill(0);
        for (char c : s)
            counts[c-'a']++;
        int pos = 0;
        for (int i = 0; i != s.size(); i++) {
            if (s[i] < s[pos])
                pos = i;
            if (--counts[s[i]-'a'] == 0)
                break;
        }
        if (s.empty())
            return "";
        string substr = s.substr(pos+1);
        substr.erase(std::remove(substr.begin(), substr.end(), s[pos]), substr.end());
        
        return s[pos] + removeDuplicateLetters(substr);
    }
};
