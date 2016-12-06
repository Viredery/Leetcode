class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        dic = {}
        for string in strs:
            l = list(string)
            l.sort()
            strSorted = "".join(l)
            if strSorted in dic:
                dic[strSorted].append(string) 
            else:
                dic[strSorted] = [string]
        return dic.values()