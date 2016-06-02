public class Solution {
    public boolean isUgly(int num) {
        int result = num;
        if (result <= 0)
            return false;
        while (result % 2 == 0)
            result /= 2;
        while (result % 3 == 0)
            result /= 3;
        while (result % 5 == 0)
            result /= 5;
        return result == 1;
    }
}