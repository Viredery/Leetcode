class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        self.rotateCircle(matrix, 0, len(matrix)-1)
    
    def rotateCircle(self, matrix, start, end):
        """
        :type matrix: List[List[int]]
        :type start: int
        :type end: int
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        if end <= start:
            return
        for pos in xrange(end-start):
            tmp = matrix[start][start+pos]
            matrix[start][start+pos] = matrix[end-pos][start]
            matrix[end-pos][start] = matrix[end][end-pos]
            matrix[end][end-pos] = matrix[start+pos][end]
            matrix[start+pos][end] = tmp
        self.rotateCircle(matrix, start+1, end-1)