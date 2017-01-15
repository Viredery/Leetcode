class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        left, right = 0, len(matrix) - 1
        while right - left >= 2:
            mid = (left + right) / 2 
            if matrix[mid][0] is target:
                return True
            elif matrix[mid][0] < target:
                left = mid
            else:
                right = mid
        # 应该用二分法
        row = right if matrix[right][0] <= target else left
        return True if target in matrix[row] else False