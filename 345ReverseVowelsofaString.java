public class Solution {
    public String reverseVowels(String s) {
        char[] word = s.toCharArray();
        int leftPos = 0, rightPos = word.length - 1;
        while (leftPos < rightPos) {
            while (leftPos < rightPos) {
                if (("" + word[leftPos]).matches("[aeiouAEIOU]"))
                    break;
                leftPos++;
            }
            while (leftPos < rightPos) {
                if (("" + word[rightPos]).matches("[aeiouAEIOU]"))
                    break;
                rightPos--;
            }
            if (leftPos < rightPos) {
                char tmp = word[leftPos];
                word[leftPos++] = word[rightPos];
                word[rightPos--] = tmp;
            }
        }
        String result = new String(word);
        return result;
    }
}
