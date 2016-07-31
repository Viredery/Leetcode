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
        if not root:
            return []
        elif not root.left and not root.right:
            return [str(root.val)]
        else:
            return list(map(lambda x: str(root.val)+"->"+x, self.binaryTreePaths(root.left)+self.binaryTreePaths(root.right)))