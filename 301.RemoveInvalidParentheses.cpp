class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        helper(s, res, 0, 0, make_tuple('(', ')'));
        return res;
    }
private:
    void helper(string s, vector<string>& res, int start_i, int start_j, tuple<char, char> t) {
        for (int count = 0, i = start_i; i != s.size(); i++) {
            if (s[i] == get<0>(t))
                count++;
            if (s[i] == get<1>(t))
                count--;
            if (count >= 0)
                continue;
            for (int j = start_j; j <= i; j++) {
                if (s[j] == get<1>(t) && (j == start_j || s[j-1] != get<1>(t)))
                    helper(s.substr(0, j) + s.substr(j+1), res, i, j, t);
            }
            return;
        }
        string reversed = string(s.rbegin(), s.rend());
        if (get<0>(t) == '(')
            helper(reversed, res, 0, 0, make_tuple(')', '('));
        else
            res.push_back(reversed);
    }
};