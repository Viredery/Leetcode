class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n < 1: return False
        return (math.log10(n) / math.log10(3)) % 1 == 0