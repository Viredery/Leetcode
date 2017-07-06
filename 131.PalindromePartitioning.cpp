class Solution {
public:
    vector<vector<string>> partition(string s) {
        palindromeVec.clear();
        vector<string> vec;
        partitionRecursion(s, 0, vec);
        return palindromeVec;
    }
    void partitionRecursion(const string& s, int pos, vector<string>& vec) {
        if (pos == s.size()) {
            palindromeVec.push_back(vec);
            return;
        }
        for (int i = pos; i != s.size(); i++) {
            if (isPalindrome(s, pos, i)) {
                vec.push_back(s.substr(pos, i-pos+1));
                partitionRecursion(s, i+1, vec);
                vec.pop_back();
            }
        }
    }
private:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end)
            if (s[start++] != s[end--])
                return false;
        return true;
    }
    
    vector<vector<string>> palindromeVec;
};