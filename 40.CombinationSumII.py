class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        result, path, left = [], [], target
        self.recursion(candidates, path, left, result)
        return result
        
    def recursion(self, candidates, path, target, result):
        if target == 0 and path not in result:
            result.append(path)
        if target < 0:
            return
        if candidates:
            self.recursion(candidates[0:-1], [candidates[-1]] + path, target - candidates[-1], result)
            self.recursion(candidates[0:-1], path, target, result)