class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        const int reversed_x = reverseNumber(x);
        return x == reversed_x;
    }
private:
    int reverseNumber(int x) {
        long reverse_num = 0;
        while (x) {
            reverse_num = reverse_num * 10 + x % 10;
            x = x / 10;
        }
        if (reverse_num > static_cast<long>(std::numeric_limits<int>::max())) {
            return -1;
        }
        return reverse_num;
    }
};
