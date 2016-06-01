public class Solution {
    public int longestValidParentheses(String s) {
        int[] validParentheses = new int[s.length()];
        int longestValidParentheses = 0;
        for (int i = 0; i != s.length(); i++) {
            if (s.charAt(i) == '(')
                validParentheses[i] = 0;
            else if (i - 1 >= 0 && validParentheses[i - 1] != 0) {
                int pos = i - validParentheses[i - 1] - 1;
                if (pos >= 0 && s.charAt(pos) == '(')
                    validParentheses[i] = validParentheses[i - 1] + 2 + (pos - 1 >= 0 ? validParentheses[pos - 1] : 0);
                else
                    validParentheses[i] = 0;
            } else if (i - 1 >= 0 && s.charAt(i - 1) == '(') {
                    validParentheses[i] = i - 2 >= 0 ? validParentheses[i - 2] + 2 : 2;
            } else
                validParentheses[i] = 0;
            longestValidParentheses = Math.max(validParentheses[i], longestValidParentheses);
        }
        return longestValidParentheses;
    }
}