class Solution {
public:
    bool isHappy(int n) {
        int slow_num = n;
        int fast_num = getNextNumber(n);
        while (fast_num != 1 && fast_num != slow_num) {
            slow_num = getNextNumber(slow_num);
            fast_num = getNextNumber(getNextNumber(fast_num));
        }
        return fast_num == 1;
    }
private:
    int getNextNumber(int n) {
        int next_number = 0;
        while (n > 0) {
            next_number += std::pow(n % 10, 2);
            n /= 10;
        }
        return next_number;
    }
};
