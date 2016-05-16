public class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim();
        int pos = s.lastIndexOf(" ");
	String lastWord = new String();
        lastWord = s.substring(pos + 1);
        return lastWord.length();
    }
}
