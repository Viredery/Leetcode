class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n > 0) {
            res += (n - 1) % 26 + 'A';
            n = (n - 1) / 26;
        }
        return string(res.rbegin(), res.rend());
    }
};