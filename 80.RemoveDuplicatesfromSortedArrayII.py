class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 3:
            return len(nums)
        mDuplicates, currNum = False, nums[0]
        currPos, delNum = 1, 0
        while currPos < len(nums) - delNum:
            if nums[currPos + delNum] == currNum and mDuplicates == True:
                delNum = delNum + 1
                continue
            if nums[currPos + delNum] != currNum:
                mDuplicates, currNum = False, nums[currPos + delNum]
            else:
                mDuplicates = True
            nums[currPos] = nums[currPos + delNum]
            currPos = currPos + 1
        return len(nums) - delNum