class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(len(nums)):
            while nums[i] > 0 and nums[i] <= len(nums) and nums[i] != i + 1 and nums[i] != nums[nums[i] - 1]:
                swap = nums[i]
                nums[i], nums[swap - 1] = nums[swap - 1], swap
        for i in range(len(nums)):
            if nums[i] != i + 1:
                return i + 1
        return 1 if len(nums) == 0 else len(nums) + 1