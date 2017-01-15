class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        matrix = []
        for _ in range(n):
            matrix.append([0] * n)
        if n is 0: return matrix
        self.spiralCircle(0, 0, n-1, n-1, matrix, 1)
        return matrix
        
    def spiralCircle(self, row_lu, col_lu, row_rd, col_rd, matrix, num):
        if col_rd < col_lu or row_rd < row_lu:
            return
        if col_rd is col_lu and row_rd is row_lu:
            matrix[row_lu][col_lu] = num
            return
        for i in range(col_rd - col_lu):
            matrix[row_lu][col_lu+i] = num
            num = num + 1
        for i in range(row_rd - row_lu):
            matrix[row_lu+i][col_rd] = num
            num = num + 1
        for i in range(col_rd - col_lu):
            matrix[row_rd][col_rd-i] = num
            num = num + 1
        for i in range(row_rd - row_lu):
            matrix[row_rd-i][col_lu] = num
            num = num + 1
        self.spiralCircle(row_lu+1, col_lu+1, row_rd-1, col_rd-1, matrix, num)