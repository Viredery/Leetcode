class Solution {
public:
    bool isPalindrome(string s) {
        
        for (int start = 0, end = s.size() - 1; start < end; start++, end--) {
            while(!isalnum(s[start]))
                start++;
            while(!isalnum(s[end]))
                end--;
            if (start < end && tolower(s[start]) != tolower(s[end]))
                return false;
        }
        return true;
    }
};