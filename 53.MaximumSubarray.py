class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return None
        # Dynamic Programming
        currLargestSum, largestSuffixSum = nums[0], (nums[0] if nums[0] > 0 else 0)
        for i in range(len(nums))[1:]:
            currLargestSuffixSum = nums[i] + largestSuffixSum
            largestSuffixSum = (currLargestSuffixSum if currLargestSuffixSum > 0 else 0)
            if currLargestSuffixSum > currLargestSum:
                currLargestSum = currLargestSuffixSum
        return currLargestSum