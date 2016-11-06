class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        if k == 0:
            return False
        s = set([])
        for i in range(min(k, len(nums))):
            if nums[i] in s:
                return True
            s.add(nums[i])
        for i in range(min(k, len(nums)), len(nums)):
            if nums[i] in s:
                return True
            s.remove(nums[i - k])
            s.add(nums[i])
        return False