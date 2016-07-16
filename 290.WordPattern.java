public class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] strstr = str.split(" ");
        Map<Character, String> map = new HashMap<Character, String>();
        Set<String> set = new HashSet<String>();
        if (pattern.length() != strstr.length)
            return false;
        for (int i = 0; i != pattern.length(); i++) {
            if (map.containsKey(pattern.charAt(i))) {
                if (!map.get(pattern.charAt(i)).equals(strstr[i]))
                    return false;
            } else {
                if (map.containsValue(strstr[i]))
                    return false;
                map.put(pattern.charAt(i), strstr[i]);
            }
        }
        return true;
    }
}