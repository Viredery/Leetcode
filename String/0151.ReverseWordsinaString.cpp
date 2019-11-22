class Solution {
public:
    string reverseWords(string s) {
        int senPos = 0, wordStart = 0;
        while (wordStart < s.size()) {
            while (wordStart < s.size() && s[wordStart] == ' ')
                wordStart++;
            if (wordStart == s.size())
                break;
            int wordEnd = wordStart;
            while (wordEnd < s.size() && s[wordEnd] != ' ')
                wordEnd++;
            std::reverse(s.begin() + wordStart, s.begin() + wordEnd);
            if (senPos)
                s[senPos++] = ' ';
            while (wordStart < wordEnd)
                s[senPos++] = s[wordStart++];
        }
        s.erase(s.begin() + senPos, s.end());
        std::reverse(s.begin(), s.end());
        return s;
    }
};
