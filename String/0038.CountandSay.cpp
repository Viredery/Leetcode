class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int i = 2; i <= n; i++) 
            str = nextNum(str);
        return str;
    }
private:
    string nextNum(string s) {
        char num = s[0];
        int pos = 1, times = 1;
        string res = "";
        while (pos < s.size()) {
            if (s[pos] == num)
                times++;
            else {
                res += ('0' + times);
                res += num;
                num = s[pos];
                times = 1;
            }
            pos++;
        }
        res += ('0' + times);
        res += num;
        return res;
    }
};
