class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        rowPaths, mark = [], False
        for i in range(len(obstacleGrid[0])):
            if obstacleGrid[0][i] is 1:
                mark = True
            if mark: rowPaths.append(0)
            else: rowPaths.append(1)
        for j in range(1, len(obstacleGrid)):
            for i in range(len(obstacleGrid[0])):
                if obstacleGrid[j][i] is 1:
                    rowPaths[i] = 0
                else:
                    if i != 0:
                        rowPaths[i] = rowPaths[i] + rowPaths[i-1]
        return rowPaths[-1]