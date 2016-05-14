public class Solution {
    public int lengthOfLastWord(String s) {
        int pos = s.lastIndexOf(" ");
	String lastWord = new String();
        lastWord = s.substring(pos + 1);
        return lastWord.length();
    }
}
