public class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1)
            return s;
        int nNum = numRows * 2 - 2;
        int length = s.length();
        int pos = 0;
        StringBuilder sb = new StringBuilder(length);
        while (pos < length) {
            sb.append(s.charAt(pos));
            pos += nNum;
        }
        int leftPos = 1, rightPos = nNum - 1;
        while (leftPos < rightPos) {
            int l = leftPos, r = rightPos;
            while(r < length) {
                sb.append(s.charAt(l));
                sb.append(s.charAt(r));
                l += nNum;
                r += nNum;
            }
            if (l < length)
                sb.append(s.charAt(l));
            
            leftPos++;
            rightPos--;
        }
        if (leftPos == rightPos) {
            while (leftPos < length) {
                sb.append(s.charAt(leftPos));
                leftPos += nNum;
            }
        }
        return new String(sb);
    }
}