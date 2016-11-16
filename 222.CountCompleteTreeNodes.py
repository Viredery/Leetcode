# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        p, depth = root, 0
        while p:
            p, depth = p.left, depth + 1
        return 0 if depth == 0
            else self.countLastLevelNodes(root, depth) + 2 ** (depth - 1) - 1
        
    def countLastLevelNodes(self, root, depth):
        if depth == 1: return 1
        p, currDepth = root.right, 1
        while p:
            p, currDepth = p.left, currDepth + 1
        return self.countLastLevelNodes(root.left, depth - 1) if currDepth != depth
            else self.countLastLevelNodes(root.right, depth - 1) + 2 ** (depth - 2)