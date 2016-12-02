class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        grip = [1 for col in range(n)]
        for _ in range(1, m):
            for i in range(1, n):
                grip[i] = grip[i] + grip[i-1]
        return grip[n-1]