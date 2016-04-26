public class Solution {
    public boolean isPowerOfFour(int num) {
        String binaryString = Integer.toBinaryString(new Integer(num));
        if (num == 1)
            return true;
        // 1431655764 transfer to binary: 01010101010101010101010101010100
        else if ((num | (1431655764)) == 1431655764 && binaryString.matches("0*10*"))
            return true;
        return false;
    }
}