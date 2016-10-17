class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        majority, times = nums[0], 1
        for num in nums[1:]:
            if times == 0:
                majority, times = num, 1
            elif num == majority:
                times = times +  1
            else:
                times = times - 1
        return majority