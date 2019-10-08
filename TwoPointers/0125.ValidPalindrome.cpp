class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isValid(s[l]))
                l++;
            while (l < r && !isValid(s[r]))
                r--;
            if (l < r && tolower(s[l++]) != tolower(s[r--]))
                return false;
        }
        return true;
    }
private:
    bool isValid(char c) {
        if (tolower(c) <= 'z' && tolower(c) >= 'a')
            return true;
        if (c <= '9' && c >= '0')
            return true;
        return false;
    }
};
