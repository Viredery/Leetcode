class Solution {
public:
    int calculate(string s) {
        std::vector<int> st;
        char prev_operator = '+';
        int num = 0;
        int idx = 0;
        while (idx < s.size()) {
            const char c = s[idx++];
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || idx == s.size()) {
                if (prev_operator == '+') {
                    st.push_back(num);
                } else if (prev_operator == '-') {
                    st.push_back(-num);
                } else if (prev_operator == '*') {
                    st.back() *= num;
                } else if (prev_operator == '/') {
                    st.back() /= num;
                }
                prev_operator = c;
                num = 0;
            }
        }
        return std::accumulate(st.begin(), st.end(), 0);
    }
};
