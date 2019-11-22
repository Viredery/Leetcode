class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int i = 2; i <= n; i++) 
            str = nextNum(str);
        return str;
    }
private:
    string nextNum(const string& s) {
        string res;
        int pos = 0;
        while (pos < s.size()) {
            int k = pos;
            while (k < s.size() && s[k] == s[pos])
                k++;
            res += std::to_string(k - pos) + s[pos];
            pos = k;
        }
        return std::move(res);
    }
};
