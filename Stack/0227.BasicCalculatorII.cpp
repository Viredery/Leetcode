class Solution {
public:
    int calculate(string s) {
        int res = 0, tmpRes = 0;
        int operand = 0;
        char lastOps = '+';
        vector<char> ops = {'+', '-', '*', '/'};
            
        for (int i = 0; i != s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9')
                operand = operand * 10 + (s[i] - '0');
            if (i + 1 == s.size() || find(ops.begin(), ops.end(), s[i]) != ops.end()) {
                if (lastOps == '*')
                    tmpRes *= operand;
                else if (lastOps == '/')
                    tmpRes /= operand;
                else if (lastOps == '+') {
                    res += tmpRes;
                    tmpRes = operand;
                } else if (lastOps == '-') {
                    res += tmpRes;
                    tmpRes = -operand;
                }
                operand = 0;
                lastOps = s[i];
            }  
        }
        return res + tmpRes;
    }
};
