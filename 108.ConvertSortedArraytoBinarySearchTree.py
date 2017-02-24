# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if len(nums) == 0:
            return None
        start, end = 0, len(nums) - 1
        mid = (start + end) / 2
        node = TreeNode(nums[mid])
        self.subsetToBST(nums, start, mid - 1, mid, node)
        self.subsetToBST(nums, mid + 1, end, mid, node)
        return node
        
    def subsetToBST(self, nums, start, end, pos, node):
        if start > end:
            return
        mid = (start + end) / 2
        childNode = TreeNode(nums[mid])
        if pos > mid:
            node.left = childNode
        else:
            node.right = childNode
        self.subsetToBST(nums, start, mid - 1, mid, childNode)
        self.subsetToBST(nums, mid + 1, end, mid, childNode)