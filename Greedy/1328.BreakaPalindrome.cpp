class Solution {
public:
    string breakPalindrome(string palindrome) {
        for (int i = 0; i < palindrome.size() / 2; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome; 
            }
        }
        if (palindrome.size() <= 1) {
            return "";
        }
        palindrome[palindrome.size() - 1] = 'b';
        return palindrome;
    }
};
