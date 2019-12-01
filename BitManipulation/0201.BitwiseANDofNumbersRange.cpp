class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        for (int i = 0; (1ll << i) <= m; i++) {
            if (m >> i & 1 && ((m & ~((1 << i) - 1ll)) + (1 << i) > n))
                res += 1 << i;
        }
        return res;
    }
};
