class Solution {
public:
    int findComplement(int num) {
        int res = 0, t = 0;
        while (num) {
            res += !(num & 1) << t;
            num >>= 1;
            t++;
        }
        return res;
    }
};
