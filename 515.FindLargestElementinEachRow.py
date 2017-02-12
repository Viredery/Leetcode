class Solution(object):
    def findValueMostElement(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        queue, result = [], []
        if root is None:
            return result
        queue.append(root)
        num, curMax = 1, None
        while queue:
            r = queue[0]
            queue = queue[1:]
            if curMax is None or curMax < r.val:
                curMax = r.val
            if r.left:
                queue.append(r.left)
            if r.right:
                queue.append(r.right)
            num = num - 1
            if num == 0:
                result.append(curMax)
                num, curMax = len(queue), None
        return result