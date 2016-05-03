public class Solution {
    public int romanToInt(String s) {
        int i;
        Map<Character, Integer> romanNumeral = new HashMap<Character, Integer>();
        char key[] = {'I','V','X','L','C','D','M'};
        int value[] = {1, 5, 10, 50, 100, 500, 1000};
        for (i = 0; i != 7; i++) {
            romanNumeral.put(key[i], value[i]);
        }
        int length = s.length();
        int prevNum = romanNumeral.get(s.charAt(0)), currNum;
        int result = 0;
        for (i = 1; i != length; i++) {
            currNum = romanNumeral.get(s.charAt(i));
            result += prevNum < currNum ? (-prevNum) : prevNum;
            prevNum = currNum;
        }
        result += prevNum;
        return result;
    }
}