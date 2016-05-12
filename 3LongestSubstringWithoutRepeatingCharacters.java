public class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        int length = 0, maxLength = 0, startPos = 0, pos;
        for (pos = 0; pos != s.length(); pos++) {
            char currentVal = s.charAt(pos);
            if (!map.containsKey(currentVal) || map.get(currentVal) < startPos) {
                map.put(currentVal, pos);
                length++;
            } else {
                if (length > maxLength)
                    maxLength = length;
                startPos = map.get(currentVal) + 1;
                length = pos - startPos + 1;
                map.put(currentVal, pos);
            }
        }
        if (length > maxLength)
            maxLength = length;
        return maxLength;
    }
}