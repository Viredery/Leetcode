class Solution {
public:
    int trailingZeroes(int n) {
        int trailing_zero_num = 0;
        while (n / 5 > 0) {
            n /= 5;
            trailing_zero_num += n;
        }
        return trailing_zero_num;
    }
};
