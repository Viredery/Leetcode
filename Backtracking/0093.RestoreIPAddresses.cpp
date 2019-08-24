class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12)
            return {};
        vector<string> res;
        vector<int> dot;
        backtracking(s, 0, dot, res);
        return res;
    }
private:
    void backtracking(const string& s, int pos, 
                      vector<int>& dot, vector<string>& res) {
        if (pos >= s.size())
            return;
        if (dot.size() == 3) {
            int start = dot[2];
            if (s[start] == '0' && start + 1 != s.size())
                return;
            if (stoi(s.substr(start)) <= 255) {
                string ip;
                int start = 0;
                for (int i = 0; i != 3; i++) {
                    ip += s.substr(start, dot[i]-start);
                    ip += '.';
                    start = dot[i];
                }
                ip += s.substr(start);
                res.push_back(move(ip));
            }
            return;
        }

        if (pos + 1 < s.size()) {
            dot.push_back(pos + 1);
            backtracking(s, pos + 1, dot, res);
            dot.pop_back();
        }
        if (s[pos] == '0')
            return;
        if (pos + 2 < s.size()) {
            dot.push_back(pos + 2);
            backtracking(s, pos + 2, dot, res);
            dot.pop_back();
        }
        if (pos + 3 < s.size() && stoi(s.substr(pos, 3)) <= 255) {
            dot.push_back(pos + 3);
            backtracking(s, pos + 3, dot, res);
            dot.pop_back();
            
        }
    }
};
