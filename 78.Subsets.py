class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        result.append([])
        if len(nums) is 0:
            return result
        stack, cur = [0], 0
        result.append([nums[0]])
        while stack or cur + 1 != len(nums):
            if cur + 1 < len(nums):
                cur = cur + 1
                stack.append(cur)
                result.append([nums[i] for i in stack])
            else:
                stack.pop()
                if stack:
                    cur = stack.pop()
        return result