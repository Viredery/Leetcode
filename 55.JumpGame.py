class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return self.canJumpFromTo(nums, 0, len(nums)-1)
        
    def canJumpFromTo(self, nums, start, end):
        while start + nums[start] < end:
            if nums[start] == 0:
                return False
            for i in range(1, nums[start]):
                if nums[start + i] > nums[start] - i:
                    start = start + i
                    break
            else:
                start = start + nums[start]
        return True
        