class Solution {
public:
    int getSum(int a, int b) {
        if (!b)
            return a;
        int res = (unsigned int)a ^ b, carry = ((unsigned int)a & b) << 1;
        return getSum(res, carry);
    }
};
