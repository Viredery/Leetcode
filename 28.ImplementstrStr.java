public class Solution {
    public int strStr(String haystack, String needle) {
        if (null == needle || needle.isEmpty())
            return 0;
        if (null == haystack || needle.isEmpty())
            return -1;
        int hLength = haystack.length();
        int nLength = needle.length();
        int size = hLength - nLength;
        for (int i = 0; i <= size; i++) {
            int j;
            for (j = 0; j != nLength; j++) {
                if (haystack.charAt(j + i) != needle.charAt(j))
                    break;
            }
            if (j == nLength)
                return i;
        }
        return -1;
    }
}