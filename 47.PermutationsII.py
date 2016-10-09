class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 1:
            return [[nums[0]]]
        positions, result, order = [i for i in range(len(nums))], [], []
        nums.sort()
        self.generate(nums, positions, order, result)
        return result
        
    def generate(self, nums, positions, order, result):
        if len(positions) == 2:
            order.extend(positions)
            result.append([nums[i] for i in order])
            if nums[positions[0]] != nums[positions[1]]:
                order[-1], order[-2] = positions[0], positions[1]
                result.append([nums[i] for i in order])
            order.pop(); order.pop()
            return
        items = positions[:]
        items.sort()
        for i in range(len(items)):
            if i == 0 or (i > 0 and nums[items[i]] != nums[items[i - 1]]):
                positions.remove(items[i])
                order.append(items[i])
                self.generate(nums, positions, order, result)
                order.pop()
                positions.append(items[i])