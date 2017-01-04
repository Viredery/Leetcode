class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0:
            return 1.
        return self.myPostivePow(1/x, -n) if n < 0 else self.myPostivePow(x, n)

    def myPostivePow(self, x, n):
        if n == 1:
            return x
        return self.myPow(x * x, n >> 1) * (x if n & 1 else 1)