class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        reverseResult = 0
        for _ in range(32):
            reverseResult = (reverseResult << 1) | (n & 1)
            n = n >> 1
        return reverseResult