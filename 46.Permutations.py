class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 1:
            return [[nums[0]]]
        positions, result, order = [i for i in range(len(nums))], [], []
        self.generate(nums, positions, order, result)
        return result
        
    def generate(self, nums, positions, order, result):
        if len(positions) == 2:
            order.extend(positions)
            result.append([nums[i] for i in order])
            order[-1], order[-2] = positions[0], positions[1]
            result.append([nums[i] for i in order])
            order.pop(); order.pop()
            return
        items = positions[:]
        for item in items:
            positions.remove(item)
            order.append(item)
            self.generate(nums, positions, order, result)
            order.pop()
            positions.append(item)