public class Solution {
    public int getSum(int a, int b) {
        int sum = a | b;
        int carry = a & b;
        while (carry != 0) {
            sum = sum ^ carry;
            a = carry << 1;
            b = sum;
            sum = a | b;
            carry = a & b;
        }
        return sum;
    }
}