class Solution(object):
    def convertTo7(self, num):
        """
        :type num: int
        :rtype: str
        """
        posNum = abs(num)
        result = ''
        while posNum != 0:
            result = str(posNum % 7) + result
            posNum = posNum / 7
        if result != '' and result[0] == '0':
            result = result[1:]
        if result == '':
            result = '0'
        return result if abs(num) == num else ('-' + result)