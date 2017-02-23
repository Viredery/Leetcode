# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        res, stackqueue = [], []
        if root != None:
            stackqueue.append(root)
            res.append([root.val])
        FlagRightFirst = True
        while stackqueue:
            length , levelVals = len(stackqueue), []
            for _ in range(length):
                if FlagRightFirst:
                    node = stackqueue.pop(-1)
                    if node.right:
                        stackqueue.insert(0, node.right)
                        levelVals.append(node.right.val)
                    if node.left:
                        stackqueue.insert(0, node.left)
                        levelVals.append(node.left.val)
                else:
                    node = stackqueue.pop(0)
                    if node.left:
                        stackqueue.append(node.left)
                        levelVals.append(node.left.val)
                    if node.right:
                        stackqueue.append(node.right)
                        levelVals.append(node.right.val)
            if levelVals:
                res.append(levelVals)
            FlagRightFirst = (False == FlagRightFirst)
        return res