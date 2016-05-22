public class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length())
            return false;
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        for (int i = 0; i != s.length(); i++) {
            if (map.containsKey(s.charAt(i))) {
                map.put(s.charAt(i), map.get(s.charAt(i)) + 1);
            } else {
                map.put(s.charAt(i), 1);
            }
        }
        for (int j = 0; j != t.length(); j++) {
            if (map.containsKey(t.charAt(j))) {
                if (map.get(t.charAt(j)).equals(new Integer(1)))
                    map.remove(t.charAt(j));
                else
                    map.put(t.charAt(j), map.get(t.charAt(j)) - 1);
            }
            else
                return false;
        }
        if (map.isEmpty()) {
            return true;
        } else {
            return false;
        }
    }
}