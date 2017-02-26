# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        numList = []
        self.traverse(root, numList)
        if len(numList) < 2:
            return None
        minDiff = numList[1] - numList[0]
        for i in range(2, len(numList)):
            if numList[i] - numList[i - 1] < minDiff:
                minDiff = numList[i] - numList[i - 1]
        return minDiff
    
    def traverse(self, root, numList):
        if root == None:  
            return  
        self.traverse(root.left, numList)
        numList.append(root.val)
        self.traverse(root.right, numList)  