// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int high = n, small = 1;
        int median = small + (high - small) / 2;
        int result = 0;
        while ((result = guess(median)) != 0) {
            if (result == 1) {
                small = median + 1;
            } else
                high = median - 1;
            if (high < 1)
                return 1;
            if (small > n)
                return n;
            median = small + (high - small) / 2;
        }
        return median;
    }
};