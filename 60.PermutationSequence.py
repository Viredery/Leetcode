class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        numPos, result, numbers = [], '', [i + 1 for i in range(n)]
        factorial = math.factorial(n)
        for i in range(n,0,-1):
            factorial = factorial / i
            pos = (k-1) / factorial
            result = result + str(numbers.pop(pos))
            k = k - factorial * pos
        return result