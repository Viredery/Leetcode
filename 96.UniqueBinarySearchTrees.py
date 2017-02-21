class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        numTreesList = [1, 1, 2]
        for i in range(3, n + 1):
            iNumTrees = 0
            for j in range(1, i + 1):
                 iNumTrees = iNumTrees + numTreesList[j - 1] * numTreesList[i - j]
            numTreesList.append(iNumTrees)
        return numTreesList[n] if n > 0 else 1