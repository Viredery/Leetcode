public class Solution {
    public int myAtoi(String str) {
        str = str.trim();
        int result = 0;
        boolean negative = false;
        int i = 0;
        if (str.isEmpty())
            return 0;
        if (str.charAt(i) == '-') {
            negative = true;
            i++;
        } else if (str.charAt(i) == '+') {
            negative = false;
            i++;
        }
        for(; i != str.length(); i++) {
            int num = str.charAt(i) - '0';
            if (num >= 0 && num <= 9) {
                int oldResult = result;
                result = result * 10 + num;
                if (result / 10 != oldResult) {
                    result = 2147483647;
                    break;
                }
            } else {
                break;
            }
        }
        if (i == str.length() && result == 2147483647 && negative == true)
            return -2147483647;
        else if (result == 2147483647 && negative == true)
            return -2147483648;
        else if (negative == true)
            return -result;
        else
            return result;
    }
}