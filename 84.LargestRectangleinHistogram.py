class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        stack = []
        rectangle = 0
        for pos, height in enumerate(heights):
            cur_pos = pos
            while len(stack) > 0 and stack[-1][0] > height:
                pre_state = stack.pop()
                cur_pos = pre_state[1]
                rectangle = max(pre_state[0] * (pos - pre_state[1]), rectangle)
            if len(stack) == 0 or stack[-1][0] < height:
                stack.append((height, cur_pos))
        while len(stack) > 0:
            pre_state = stack.pop()
            rectangle = max(pre_state[0] * (len(heights) - pre_state[1]), rectangle)
        return rectangle
