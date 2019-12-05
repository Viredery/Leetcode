class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        if (n == 1)
            return 0;
        if (n <= 3)
            return n;
        for (int i = 2; i <= n; i++)
            while (n % i == 0)
                res += i, n /= i;
            
        return res;
    }
};
