public class Solution {
    public int divide(int dividend, int divisor) {
        if (0 == divisor)
            return dividend >= 0 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
        if (0 == dividend)
            return 0;
        if (dividend == Integer.MIN_VALUE) {
            if (divisor == -1)
                return Integer.MAX_VALUE;
            if (divisor == Integer.MIN_VALUE)
                return 1;
        }
        if (divisor == Integer.MIN_VALUE)
            return 0;
            
        int result = 0;
        boolean positiveResult = ((dividend > 0 && divisor > 0)
                                     || (dividend < 0 && divisor < 0)) ? true : false;
        if (dividend == Integer.MIN_VALUE) {
            dividend = positiveResult ? dividend - divisor : dividend + divisor;
            result += 1;
        }
        int absDividend = Math.abs(dividend);
        int absDivisor = Math.abs(divisor);

        int lDivisor = Integer.toBinaryString(absDivisor).length();
        while (absDividend >= absDivisor) {
            int lDividend = Integer.toBinaryString(absDividend).length();

            int num = lDividend - lDivisor;
            if (absDividend - (absDivisor << num) < 0) {
                num = num - 1;
            }
            absDividend = absDividend - (absDivisor << num);
            result += (1 << num);
        }
        return positiveResult ? result : -result;
    }
}