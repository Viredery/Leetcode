class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        bool sign = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        long lDividend = std::abs(static_cast<long>(dividend));
        long lDivisor = std::abs(static_cast<long>(divisor));
        long res = divideRecursion(lDividend, lDivisor);
        if (res >= static_cast<long>(INT_MAX))
            return sign ? INT_MIN : INT_MAX;
        return sign ? -static_cast<int>(res) : static_cast<int>(res);
    }
private:
    long divideRecursion(long dividend, long divisor) {
        if (dividend < divisor)
            return 0;
        long sum = divisor;
        long res = 1;
        while (sum + sum <= dividend) {
            sum = sum + sum;
            res = res * 2;
        }
        return res + divideRecursion(dividend - sum, divisor);
    }
};
