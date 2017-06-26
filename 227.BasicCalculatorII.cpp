class Solution {
public:
    int calculate(string s) {
        long long resMultiDiv = 0, res = 0;
        s = '+' + s;
        string numRange("0123456789 ");
        int pos = 0;
        while (pos < s.size()) {
            if (s[pos] == '+' || s[pos] == '-') {
                res += resMultiDiv;
                int endPos = s.find_first_not_of(numRange, pos + 1);
                resMultiDiv = stoll(s.substr(pos + 1, endPos - pos - 1)) * (44 - s[pos]);
                pos = endPos;
            } else if (s[pos] == ' ') {
                pos++;
            } else {
                int endPos = s.find_first_not_of(numRange, pos + 1);
                long long num = stoll(s.substr(pos + 1, endPos - pos - 1));
                if (s[pos] == '*')
                    resMultiDiv *= num;
                else
                    resMultiDiv /= num;
                pos = endPos; 
            }
        }
        return res + resMultiDiv;
    }
};