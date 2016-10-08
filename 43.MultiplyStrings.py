class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        if num1 == '0' or num2 == '0':
            return '0'
        arr1, arr2, product = [int(i) for i in num1], [int(i) for i in num2], []
        for i in xrange(len(num2)):
            product = self.twoStrAdd(product, self.strMultiChar(arr1, arr2[-i - 1]) + [0] * i)
        return ''.join([str(i) for i in product])
        
    def twoStrAdd(self, arr1, arr2):
        result, carry = [], 0
        if len(arr1) > len(arr2): arr2 = [0] * (len(arr1) - len(arr2)) + arr2
        if len(arr1) < len(arr2): arr1 = [0] * (len(arr2) - len(arr1)) + arr1
        for i in xrange(len(arr1) - 1, -1, -1):
            temp = arr1[i] + arr2[i] + carry
            result = [temp % 10] + result
            carry = temp / 10
        return [carry] + result if carry > 0 else result
        
    def strMultiChar(self, arr, num):
        result, carry = [], 0
        for i in xrange(len(arr) - 1, -1, -1):
            temp = arr[i] * num + carry
            result = [temp % 10] + result
            carry = temp / 10
        return [carry] + result if carry > 0 else result