class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0
        curMin, res = prices[0], 0
        for i in range(1, len(prices)):
            if prices[i] < curMin:
                curMin = prices[i]
            elif prices[i] - curMin > res:
                res = prices[i] - curMin
        return res