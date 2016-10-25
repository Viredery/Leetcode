class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        numberOfZeros = 0;
        while n > 0:
            n = n / 5
            numberOfZeros = numberOfZeros + n
        return numberOfZeros