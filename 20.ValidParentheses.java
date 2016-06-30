public class Solution {
    static Map<Character, Character> map = new HashMap<Character, Character>();
    static {
        map.put('(', ')');
        map.put('[', ']');
        map.put('{', '}');
    }

    public boolean isValid(String s) {
        LinkedList<Character> stack = new LinkedList<Character>();
        for (int i = 0; i != s.length(); i++) {
            Character c = s.charAt(i);
            if (map.containsKey(c))
                stack.push(map.get(c));
            else {
                if (!stack.isEmpty() && stack.peek().equals(c))
                    stack.pop();
                else
                    return false;
            }
        }
        if (stack.isEmpty())
            return true;
        else
        	return false;
    }
};