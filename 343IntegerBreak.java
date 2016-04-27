public class Solution {
    public int integerBreak(int n) {
        // n range 2 to 58 because of the limit of int
        if (n == 2) return 1;
        if (n == 3) return 2;
        int quotient = n / 3;
        int remainder = n - 3 * quotient;
        if (remainder == 0)
            return (int) Math.pow(3, quotient);
        if (remainder == 1)
            return (int) Math.pow(3, quotient - 1) * 4;
        if (remainder == 2)
            return (int) Math.pow(3, quotient) * 2;
        return 0;
    }
}