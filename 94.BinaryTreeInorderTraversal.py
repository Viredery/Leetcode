# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        inorderTraversal = []
        stack, ptr = [], root
        while stack or ptr:
            while ptr:
                stack.append(ptr)
                ptr = ptr.left
            ptr = stack.pop()
            inorderTraversal.append(ptr.val)
            ptr = ptr.right
        return inorderTraversal