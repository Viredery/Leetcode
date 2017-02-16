class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 0: return []
        nums.sort()
        res = [[]]
        curNum, curPos = None, None
        pos = len(nums) - 1
        while pos >= 0:
            if curNum != nums[pos]:
                resLength, curNum, curPos = len(res), nums[pos], pos
            for i in range(resLength):
                res.append([curNum] * (curPos - pos + 1) + res[i])
            pos = pos - 1
        return res