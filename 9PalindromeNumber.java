public class Solution {
    public boolean isPalindrome(int x) {
        String x_string = Integer.toString(x);
        int left = 0, right = x_string.length() - 1;
        while (left < right) {
            if (x_string.charAt(left) != x_string.charAt(right))
                return false;
            left++;
            right--;
        }
        return true;
    }
}