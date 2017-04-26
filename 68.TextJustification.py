class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        result = []
        curr_length, start_pos = 0, 0
        for i, word in enumerate(words):
            curr_length += len(word)
            if curr_length + i - start_pos > maxWidth:
                curr_length -= len(word)
                if i - start_pos == 1:
                    result.append(words[start_pos] + ' ' * (maxWidth - curr_length))
                else:
                    total_spaces_num = maxWidth - curr_length
                    per_spaces_num = total_spaces_num / (i - start_pos - 1)
                    slots_left_num = total_spaces_num - per_spaces_num * (i - start_pos - 1)
                    new_line = ''
                    for pos in range(start_pos, i-1):
                        new_line += words[pos] + ' ' * (per_spaces_num + (1 if pos < start_pos + slots_left_num else 0))
                    new_line += words[i-1]
                    result.append(new_line)
                curr_length = len(word)
                start_pos = i
        new_line = ''
        for pos in range(start_pos, len(words)) :
            new_line += words[pos] + ' '
        if len(new_line) < maxWidth:
            result.append(new_line + ' ' * (maxWidth - len(new_line)))
        else:
            result.append(new_line[:maxWidth])
        return result