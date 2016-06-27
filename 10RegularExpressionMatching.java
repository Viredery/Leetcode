public class Solution {
    public boolean isMatch(String s, String p) {
        return judgeEndPoint(s, 0, p, 0);
    }

    private boolean judgeEndPoint(String s, int posS, String p, int posP) {
    	if (posP == p.length() && posS == s.length())
    		return true;
        if (posP < p.length()) {
            char element = p.charAt(posP++);
        	if ('.' == element) {
        		if (posP < p.length() && '*' == p.charAt(posP)) {
        			//when ".*"
        			for (int i = posS; i <= s.length(); i++) {
        				if (true == judgeEndPoint(s, i, p, posP + 1))
        					return true;
        			}
        		} else {
        			//when "."
        			if (posS < s.length() && true == judgeEndPoint(s, posS + 1, p, posP))
        				return true;
        		}
        	} else {
        		if (posP < p.length() && '*' == p.charAt(posP)) {
        			//when "element*"
        			if (true == judgeEndPoint(s, posS, p , posP + 1))
        				return true;
        			for (int i = posS; i < s.length(); i++) {
        				if (element == s.charAt(i)) {
        				    if (true == judgeEndPoint(s, i + 1, p, posP + 1))
        				    	return true;
        				} else
        					break;
        			}
        		} else {
        			//when "element"
        			if (posS < s.length()
        			    && element == s.charAt(posS)
        				&& true == judgeEndPoint(s, posS + 1, p, posP))
        				return true;
        		} 
        	}
        }
        return false;
    }
}