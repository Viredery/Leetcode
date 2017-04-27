class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        states = [
            {' ': 0, 'sign': 1, 'digit': 2, '.': 3},
            {'digit': 2, '.': 3},
            {'digit': 2, '.': 4, 'e': 5, ' ': 8},
            {'digit': 4},
            {'digit': 4, 'e': 5, ' ': 8},
            {'sign': 6, 'digit': 7},
            {'digit': 7},
            {'digit': 7, ' ': 8},
            {' ': 8}
        ]
        cur = 0
        for c in s:
            if c == '+' or c == '-':
                c = 'sign'
            elif '0' <= c <= '9':
                c = 'digit'
            if c not in states[cur].keys():
                return False
            cur = states[cur][c]
        return cur in [2, 4, 7, 8]
        