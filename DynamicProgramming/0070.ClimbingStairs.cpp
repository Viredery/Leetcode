class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        int pre = 1, cur = 2;
        for (int i = 3; i <= n; i++) {
            int next = pre + cur;
            pre = cur;
            cur = next;
        }
        return cur;
    }
};
