class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0)
            return 0;
        int times = 1;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            times <<= 1;
        }
        return m * times;
    }
};