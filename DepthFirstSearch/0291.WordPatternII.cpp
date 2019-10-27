class Solution {
public:
    bool wordPattern(string pattern, string str) {
        return dfs(pattern, 0, str, 0, 1);
    }
private:
    unordered_map<char, string> p2s;
    unordered_map<string, char> s2p;
    
    bool dfs(string& pattern, int pos1, string& str, int pos2, int len) {
        if (pos1 == pattern.size() && pos2 == str.size())
            return true;
        if (pos1 == pattern.size() || pos2 == str.size() || pos2 + len > str.size())
            return false;
        if (dfs(pattern, pos1, str, pos2, len+1))
            return true;
        string key = str.substr(pos2, len);
        int cnt = p2s.count(pattern[pos1]);
        if (p2s.count(pattern[pos1]) && p2s[pattern[pos1]] != key)
            return false;
        if (s2p.count(key) && s2p[key] != pattern[pos1])
            return false;
        p2s[pattern[pos1]] = key;
        s2p[key] = pattern[pos1];
        if (dfs(pattern, pos1+1, str, pos2+len, 1))
            return true;
        if (p2s.count(pattern[pos1]) != cnt) {
            p2s.erase(pattern[pos1]);
            s2p.erase(key);
        }
        return false;
    }
    
};
