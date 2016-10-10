class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        i, j, k = m-1, n-1, m+n-1
        while i >= 0 and j >= 0:
            nums1[k] = nums1[i] if nums1[i] > nums2[j] else nums2[j]
            if nums1[i] > nums2[j]:
                i -= 1
            else:
                j -= 1
            k -= 1
        while j >= 0:
            nums1[k] = nums2[j]
            k -= 1
            j -= 1