# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {string[]}
    def binaryTreePaths(self, root):
        result, dictPaths = [], {"%d" % node.val: node for node in [root] if node}
        while dictPaths:
            result.extend([key for key, value in dictPaths.items() if value.left is None and value.right is None])
            dictPaths = {"%s->%d" % (key, n.val): n for key, value in dictPaths.items() for n in [value.left, value.right] if n}
        return result