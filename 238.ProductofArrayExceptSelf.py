class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        product, res = 1, []
        for num in nums:
            res.append(product)
            product = product * num
        product = 1
        for pos in range(len(nums) - 1, -1, -1):
            res[pos] = product * res[pos]
            product = product * nums[pos]
        return res