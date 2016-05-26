public class Solution {
    public int[] countBits(int num) {
        int[] result = new int[num + 1];
        int i;
        int currentPos = 1;
        int endPos = 1;
        while (endPos * 2 <= num) {
            for (i = 0; i != endPos; i++) {
                result[currentPos++] = result[i] + 1;
            }
            endPos = endPos * 2;
        }
        i = 0;
        while(currentPos <= num) {
            result[currentPos++] = result[i++] + 1;
        }
        return result;
    }
}