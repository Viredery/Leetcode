class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0: return 1
        times = []
        for i in range(n + 1)[1:]:
            if i == 1: times.append(1)
            elif i == 2: times.append(2)
            else:
                number1, number2 = times[-1], times[-2]
                times.append(number1 + number2)
        return times[-1]