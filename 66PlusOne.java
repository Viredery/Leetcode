public class Solution {
    public int[] plusOne(int[] digits) {
        int length = digits.length;
        int carryInfo = 1;  //a var has two means, NO RECOMMENDED
        for (int i = length - 1; i >= 0; i--) {
            int result = digits[i] + carryInfo;
            digits[i] = result == 10 ? 0 : result;
            carryInfo = result == 10 ? 1 : 0;
        }
        if (carryInfo == 1) {
            int[] digitsPlusOne = new int[length + 1]; //new int: initialize by default
            digitsPlusOne[0] = 1;
            return digitsPlusOne;
        } else {
            return digits;
        }
    }
}