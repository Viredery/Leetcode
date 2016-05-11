public class Solution {
    public String countAndSay(int n) {
        String result = new String("1");
        for (int i = 1; i < n; i++) {
            String prevVal = new String(result);
            result = new String("");
            char number = prevVal.charAt(0);
            int times = 1;
            int pos = 1;
            while (pos != prevVal.length()) {
                if (number == prevVal.charAt(pos))
                    times++;
                else {
                    result = result.concat(Integer.toString(times));
                    result = result.concat("" + number);
                    number = prevVal.charAt(pos);
                    times = 1;
                }
                pos++;
            }
            result = result.concat(Integer.toString(times));
            result = result.concat("" + number);
        }
        return result;
    }
}