class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res;
        for (int i = 0; i != 32; i++) {
            res <<= 1;
            res += (n & (1 << i)) > 0;
        }
        return res;
    }
};
