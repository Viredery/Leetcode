public class Solution {
    public String reverseString(String s) {
        char[] word = s.toCharArray();
        int leftPos = 0, rightPos = word.length - 1;
        while (leftPos < rightPos) {
            char tmp = word[leftPos];
            word[leftPos++] = word[rightPos];
            word[rightPos--] = tmp;
        }
        String result = new String(word);
        return result;
    }
}

