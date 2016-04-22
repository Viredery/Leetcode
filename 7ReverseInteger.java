public class Solution {
    public int reverse(int x) {
        int newX = Math.abs(x);
        int resultX = 0;
        while (newX != 0) {
            int lastpos = newX % 10;
            newX = newX / 10;
            int oldResult = resultX;
            resultX = resultX * 10 + lastpos;
            if (resultX / 10 != oldResult)
                return 0;
        }
        return x < 0 ? -resultX : resultX;
    }
}