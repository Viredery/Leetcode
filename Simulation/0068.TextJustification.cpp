class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> lines;
        int left = 0, right = 0;
        while (left < words.size()) {
            int sum = words[right].size();
            while (right + 1 < words.size()) {
                int num = words[right + 1].size();
                if (sum + 1 + num > maxWidth)
                    break;
                sum += 1 + num;
                right++;
            }
            if (right + 1 == words.size())
                lines.push_back(createLine(words, maxWidth, left, right, true));
            else
                lines.push_back(createLine(words, maxWidth, left, right, false));
            left = right = right + 1;
        }
        return lines;
    }
private:
    string createLine(vector<string>& words, int maxWidth, 
                      int left, int right, bool lastLine) {
        int sum = 0;
        for (int i = 0; i <= right-left; i++)
            sum += words[left+i].size();
        int spaces = maxWidth - sum;
        int num = right - left;

        int spaceNum = num != 0 ? spaces / num : spaces;
        int thresh = num != 0 ? spaces % num : 0;

        string line;
        for (int i = 0; i <= right-left; i++) {
            line += words[left+i];
            if (i == right-left && (lastLine || num > 0))
                break;
            if (lastLine)
                line += ' ';
            else if (i < thresh)
                line += string(spaceNum + 1, ' ');
            else 
                line += string(spaceNum, ' ');
        }
        if (line.size() != maxWidth)
            line += string(maxWidth - line.size(), ' ');
        return move(line);
    }
};
