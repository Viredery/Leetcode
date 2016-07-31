# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        result, queue = [], []
        if root:
            queue.append(root)
        while queue:
            result.append([node.val for node in queue])
            queue = [n for node in queue for n in [node.left, node.right] if n]
        return result