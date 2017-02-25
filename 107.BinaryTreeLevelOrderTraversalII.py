# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        res, queue = [], []
        if root is None: return res
        queue.append(root)
        while queue:
            levelVals = []
            length = len(queue)
            for _ in range(length):
                node = queue.pop(0)
                levelVals.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            res.insert(0, levelVals)
        return res