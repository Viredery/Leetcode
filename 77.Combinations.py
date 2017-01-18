class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        result, stack = [], []
        if k > 0 and n >= k:
            stack = [i for i in range(1, k+1)]
        elif k is 0:
            result.append([])
            return result
        else:
            return result
        cur = stack[-1]
        while stack:
            if len(stack) is k:
                result.append(stack[:])
                stack.pop()
            if stack and cur + 1 > n:
                cur = stack.pop()
            if cur + 1 <= n:
                stack.append(cur + 1)
                cur = cur + 1
        return result