class Solution {
public:
    int calculate(string s) {
        int res = 0, ops = 1, operand = 0;
        stack<int> st;
        for (int i = 0; i != s.size(); i++) {
            if (s[i] == ' ')
                continue;
            if (s[i] >= '0' && s[i] <= '9')
                operand = operand * 10 + (s[i] - '0');
            else if (s[i] == '+') {
                res += operand * ops;
                operand = 0;
                ops = 1;
            } else if (s[i] == '-') {
                res += operand * ops;
                operand = 0;
                ops = -1;
            } else if (s[i] == '(') {
                st.push(res);
                st.push(ops);
                res = 0;
                ops = 1;
            } else if (s[i] == ')') {
                res += operand * ops;
                ops = st.top();
                st.pop();
                res = st.top() + res * ops;
                st.pop();
                operand = 0;
            }
        }
        return res + ops * operand;
    }
};
