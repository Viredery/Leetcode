class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        return mySqrt(x, low, high);
    }
private:
    int mySqrt(int x, int low, int high) {
        const long mid = low + (high - low) / 2;
        if (mid * mid <= x && (mid + 1) * (mid + 1) > x) {
            return mid;
        }
        if (mid * mid > x) {
            return mySqrt(x, low, mid - 1);
        } else {
            return mySqrt(x, mid + 1, high);
        }
    }
};
