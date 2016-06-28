public class Solution {

    private static Map<Character, List<Character>> map = new HashMap<Character, List<Character>>();
    static {
        map.put('2', Arrays.asList('a', 'b', 'c'));
        map.put('3', Arrays.asList('d', 'e', 'f'));
        map.put('4', Arrays.asList('g', 'h', 'i'));
        map.put('5', Arrays.asList('j', 'k', 'l'));
        map.put('6', Arrays.asList('m', 'n', 'o'));
        map.put('7', Arrays.asList('p', 'q', 'r', 's'));
        map.put('8', Arrays.asList('t', 'u', 'v'));
        map.put('9', Arrays.asList('w', 'x', 'y', 'z'));
    }
    private List<Iterator<Character>> stack = new ArrayList<Iterator<Character>>();
    public List<String> letterCombinations(String digits) {
        List<String> combinations = new LinkedList<String>();
        char[] combination = new char[digits.length()];
        for (int i = 0; i != digits.length(); i++) {
            if (digits.charAt(i) >= '1' && digits.charAt(i) <= '9')
                stack.add(map.get(digits.charAt(i)).iterator());
            else 
                return combinations;
        }
        int pos = 0;
        while (pos != -1 && pos < digits.length()) {
            Iterator<Character> iter = stack.get(pos);
            if (iter.hasNext()) {
                combination[pos] = iter.next();
                if (pos == digits.length() - 1)
                    combinations.add(new String(combination));
                else
                    pos++;
            } else {
                stack.set(pos, map.get(digits.charAt(pos)).iterator());
                pos--;
            }
        }
        return combinations;
    }
}