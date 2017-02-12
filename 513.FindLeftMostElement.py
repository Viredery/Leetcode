# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findLeftMostNode(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        maxdepth, leftMostValue = self.findLeftMostNodeRecursion(root)
        return leftMostValue
        
    def findLeftMostNodeRecursion(self, root):
        if root is None:
            return 0, None
        rightDepth, rightValue = self.findLeftMostNodeRecursion(root.right)
        leftDepth, leftValue = self.findLeftMostNodeRecursion(root.left)
        maxDepth = rightDepth if rightDepth > leftDepth else leftDepth
        leftMostValue = rightValue if rightDepth > leftDepth else leftValue
        if leftMostValue is None:
            leftMostValue = root.val
        return maxDepth + 1, leftMostValue