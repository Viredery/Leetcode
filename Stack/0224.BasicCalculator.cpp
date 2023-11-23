class Solution {
public:
    int calculate(string s) {
       int result = 0;
       calculate(s, 0, &result);
       return result; 
    }
private:
    int calculate(const std::string& s, int start_pos, int* result) const {
        std::vector<int> st;
        char prev_operator = '+';
        int num = 0;
        int idx = start_pos;
        while (idx < s.size()) {
            const char c = s[idx++];
            if (c == '(') {
                idx = calculate(s, idx, &num);
            }
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            }
            if (c == '+' || c == '-' || c == ')' || idx == s.size()) {
                if (prev_operator == '-') {
                    num = -num;
                }
                prev_operator = c;
                st.push_back(num);
                num = 0;
            }
            if (c == ')') {
                break;
            }
        }
        *result = std::accumulate(st.begin(), st.end(), 0);
        return idx;
    }
};
