public class Solution {
    int length = 0;
    
    String longestPalindromicSubstring = new String("");
    
    public String longestPalindrome(String s) {
        length = s.length();
        if (s.isEmpty())
            return longestPalindromicSubstring;
        if (length > 0)
            longestPalindromicSubstring = String.valueOf(s.charAt(0));
        if (length > 1 && s.charAt(0) == s.charAt(1))
            longestPalindromicSubstring = s.substring(0,2);
        if (length <= 2)
            return longestPalindromicSubstring;
        for (int pos = 2; pos != length; pos++) {
            if (s.charAt(pos) == s.charAt(pos - 1)) {
                findPalindromicSubstring(s, pos - 2, pos + 1);
            }
            if (s.charAt(pos) == s.charAt(pos - 2)) {
                findPalindromicSubstring(s, pos - 3, pos + 1);
            }
        }
        return longestPalindromicSubstring;
    }
    
    private void findPalindromicSubstring(String s, int left, int right) {
        while (left >= 0 && right < length && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        if (right - left - 1 > longestPalindromicSubstring.length())
            longestPalindromicSubstring = s.substring(left + 1, right);
    }
}