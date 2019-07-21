class Solution {
public:
    int reverse(int x) {
        int revX = 0;
        while (x != 0) {
            int remainder = x % 10;
            x = x / 10;
            if (revX > INT_MAX / 10 || (revX == INT_MAX / 10 && remainder == 7)) 
                return 0;
            if (revX < INT_MIN / 10 || (revX == INT_MIN / 10 && remainder == -8)) 
                return 0;
            revX = revX * 10 + remainder;
        }
        return revX;
    }
};
