class Solution {
public:
    int calculate(string s) {
        int res = 0;
        vector<int> ops, nums;
        int op = 1, num = 0;
        for (int i = 0; i != s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9')
                num = num * 10 + s[i] - '0';
            else if (s[i] == '+') {
                res += op * num;
                num = 0;
                op = 1;
            } else if (s[i] == '-') {
                res += op * num;
                num = 0;
                op = -1;
            } else if (s[i] == '(') {
                ops.push_back(op);
                nums.push_back(res);
                res = 0;
                op = 1;
            } else if (s[i] == ')') {
                res = nums.back() + ops.back() * (res + op * num);
                nums.pop_back();
                ops.pop_back();
                num = 0;
                op = 1;

            }
        }
        return res + num * op;
    }
};