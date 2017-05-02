class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        pos_dict = {}
        for c in t:
            pos_dict[c] = pos_dict.get(c, 0) + 1
        left, t_len = 0, len(t)
        head, min_len = 0, None
        for right in range(len(s)):
            if s[right] not in pos_dict:
                continue
            if pos_dict[s[right]] > 0:
                t_len = t_len - 1
            pos_dict[s[right]] = pos_dict[s[right]] - 1
            while t_len == 0:
                if min_len is None or right - left + 1 < min_len:
                        min_len = right - left + 1
                        head = left
                if s[left] in pos_dict:
                    pos_dict[s[left]] = pos_dict[s[left]] + 1
                    if pos_dict[s[left]] > 0:
                        t_len = 1
                left += 1
        if min_len is None:
            return ""
        return s[head : head + min_len]
