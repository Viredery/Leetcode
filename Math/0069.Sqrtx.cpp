class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return x;
        long res = x;
        while (res * res > x)
            res = (res + x / res) / 2;
        return static_cast<int>(res);
    }
};
