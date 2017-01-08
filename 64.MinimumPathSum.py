class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rowMinimum = [0]
        for i in range(len(grid[0])):
            rowMinimum.append(rowMinimum[-1] + grid[0][i])
        del rowMinimum[0]
        for j in range(len(grid))[1:]:
            for i in range(len(grid[0])):
                if i == 0:
                    rowMinimum[i] = rowMinimum[i] + grid[j][i]
                else:
                    rowMinimum[i] = (rowMinimum[i] if rowMinimum[i-1] > rowMinimum[i] else rowMinimum[i-1]) + grid[j][i]
        return rowMinimum[-1]