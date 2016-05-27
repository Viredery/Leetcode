public class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length())
            return false;
        Map<Character, Character> charReplaced = new HashMap<Character, Character>();
        for (int i = 0; i != s.length(); i++) {
            char cLeft = s.charAt(i);
            char cRight = t.charAt(i);
            if (!charReplaced.containsKey(cLeft)) {
                if (charReplaced.containsValue(cRight))
                    return false;
                charReplaced.put(cLeft, cRight);
            } else if (!charReplaced.get(cLeft).equals(new Character(cRight)))
                return false;
        }
        return true;
    }
}