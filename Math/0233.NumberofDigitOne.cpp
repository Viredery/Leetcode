class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long division = i * 10;
            res += n / division * i + min(max(n % division - i + 1, 0LL), i);
        }
        return res;
    }
};