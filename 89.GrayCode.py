class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        res = [0]
        if n == 0:
            return res
        for i in range(1, n+1):
            pos, base = len(res) - 1, 2 ** (i - 1)
            for j in range(pos, -1, -1):
                res.append(res[j] + base)
        return res