class Solution {
public:
    int bulbSwitch(int n) {
        if (n == 0)
            return 0;
        if (n <= 2)
            return 1;
        for (int i = 1; i != n; i++) {
            if (i * i > n)
                return i-1;
            else if (i * i == n)
                return i;
        }
    }
};