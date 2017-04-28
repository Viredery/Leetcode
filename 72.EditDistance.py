class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        dp = [[i for i in range(len(word1)+1)]]
        for i in range(1, len(word2)+1):
            dp.append([i])
            
        for i in range(1, len(word2)+1):
            for j in range(1, len(word1)+1):
                if word1[j-1] == word2[i-1]:
                    dp[i].append(dp[i-1][j-1])
                else:
                    dp[i].append(min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])+1)
        return dp[-1][-1]