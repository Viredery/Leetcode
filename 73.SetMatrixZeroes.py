class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        m, n, markFirstRow = len(matrix), len(matrix[0]), not all(matrix[0])
        for i in range(1, m):
            markRow = False
            for j in range(n):
                if matrix[i][j] is 0:
                    markRow = True
                    matrix[0][j] = 0
            if markRow:
                matrix[i] = [0] * n
        for i in range(n):
            if matrix[0][i] is 0:
                for j in range(m):
                    matrix[j][i] = 0
        if markFirstRow:
            matrix[0] = [0] * n