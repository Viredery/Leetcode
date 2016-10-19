class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        stack = []
        while n:
            number = (n - 1) % 26
            stack.append(chr(number + 65))
            n = (n - 1) / 26
        result = ""
        while stack:
            result = result + stack[-1]
            del stack[-1]
        return result