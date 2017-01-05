class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        order = []
        if len(matrix) == 0: return order
        self.spiralCircle(matrix, 0, 0, len(matrix)-1, len(matrix[0])-1, order)
        return order
        
    def spiralCircle(self, matrix, row_lu, col_lu, row_rd, col_rd, order):
        if col_rd < col_lu or row_rd < row_lu:
            return
        if col_rd == col_lu and row_rd == row_lu:
            order.append(matrix[row_lu][col_lu])
            return
        if col_rd == col_lu:
            for i in range(row_rd - row_lu + 1):
                order.append(matrix[row_lu+i][col_rd])
            return
        if row_rd == row_lu:
            for i in range(col_rd - col_lu + 1):
                order.append(matrix[row_lu][col_lu+i])
            return
        for i in range(col_rd - col_lu):
            order.append(matrix[row_lu][col_lu+i])
        for i in range(row_rd - row_lu):
            order.append(matrix[row_lu+i][col_rd])
        for i in range(col_rd - col_lu):
            order.append(matrix[row_rd][col_rd-i])
        for i in range(row_rd - row_lu):
            order.append(matrix[row_rd-i][col_lu])
        self.spiralCircle(matrix, row_lu+1, col_lu+1, row_rd-1, col_rd-1, order)