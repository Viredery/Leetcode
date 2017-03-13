class Solution {
public:
    bool isMatch(string s, string p) {
        std::deque<bool> flagArr(s.size() + 1);
        flagArr[0] = true;
        int pos = 0;
        while (pos != p.size()) {
            if ('?' == p[pos]) {
                for (int i = flagArr.size(); i != 0; i--)
                    flagArr[i] = flagArr[i-1];
                pos++;
            } else if ('*' == p[pos]) {
                while (pos != p.size() && '*' == p[pos])
                    pos++;
                int i = 0;
                while (i != flagArr.size() && false == flagArr[i])
                    i++;
                while (i != flagArr.size())
                    flagArr[i++] = true;
            } else {
                for (int i = flagArr.size() - 1; i != 0; i--)
                    flagArr[i] = flagArr[i-1] && s[i - 1] == p[pos];
                pos++;                
            }
            flagArr[0] = flagArr[0] && '*' == p[pos - 1];
        }
        return flagArr[s.size()];
    }
};