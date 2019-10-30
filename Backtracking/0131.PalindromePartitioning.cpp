class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> split;
        
        backtracking(s, 0, split, res);
        return res;
    }
private:
    void backtracking(string s, int pos, vector<string>& split, vector<vector<string>>& res) {
        if (pos == s.size()) {
            res.push_back(split);
            return;
        }
        
        for (int i = pos; i != s.size(); i++) {
            if (!isPalindrome(s, pos, i))
                continue;
            split.push_back(s.substr(pos, i-pos+1));
            backtracking(s, i+1, split, res);
            split.pop_back();
        }
    }
    
    bool isPalindrome(string& s, int l, int r) {
        while (l < r)
            if (s[l++] != s[r--])
                return false;
        return true;
    }
};
