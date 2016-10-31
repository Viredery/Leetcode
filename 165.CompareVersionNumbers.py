class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        arr1, arr2 = map(int, version1.split('.')), map(int, version2.split('.'))
        table = [-1, 1]
        while arr1 and arr2:
            if (arr1[0] != arr2[0]):
                return table[arr1[0] > arr2[0]]
            arr1, arr2 = arr1[1:], arr2[1:]
        if sum(arr1 + arr2) == 0:
            return 0
        return table[len(arr1) > len(arr2)]