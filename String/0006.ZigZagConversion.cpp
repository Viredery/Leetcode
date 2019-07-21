class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        string res;
        int n = s.size();
        int cycleLen = numRows * 2 - 2;
        
        for (int i = 0; i != numRows; i++) {
            for (int j = i; j < n; j += cycleLen) {
                res += s[j];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i * 2 < n)
                    res += s[j + cycleLen - i * 2];
            }
        }
        return res;
    }
};
