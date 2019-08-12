class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == INT_MIN) {
            x = x * x;
            n = n / 2;
        }
        return n > 0 ? helpr(x, n) : helpr(1/x, -n);
    }
private:
    double helpr(double x, int n) {
        if (n == 1)
            return x;
        return n % 2 == 0 ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
    }
};
