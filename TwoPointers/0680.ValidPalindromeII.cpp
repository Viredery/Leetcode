class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if (s[left] != s[right]) {
                return IsPalindrome(s, left, right - 1) || IsPalindrome(s, left + 1, right);
            }
            left++;
            right--;   
        }
        return true;
    }
private:
    bool IsPalindrome(const std::string& s, int left, int right) {
         while (left < right) {
             if (s[left++] != s[right--]) {
                 return false;
             }
         }
         return true;
    }
};
