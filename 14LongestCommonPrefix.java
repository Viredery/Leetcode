public class Solution {
    public String longestCommonPrefix(String[] strs) {
        String prefixString = new String();
        int length = strs.length;
        if (length == 0)
            return prefixString;
        int pos = 0;
        char prexChar;
        while(true) {
            if(pos < strs[0].length())
                prexChar = strs[0].charAt(pos);
            else
                return prefixString;
            for (int i = 1; i < length; i++) {
                if (strs[i].length() <= pos || strs[i].charAt(pos) != prexChar)
                    return prefixString;
            }
            prefixString = prefixString.concat("" + prexChar);
            pos++;
        }
    }
}