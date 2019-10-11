class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        string tmp = "hot";
        int length = 0;
        set<string> paths;
        paths.insert(beginWord);
        vector<int> visited(wordList.size(), 0);
        while (length < wordList.size()) {
            set<string> nexts;
            for (auto iter = paths.begin(); iter != paths.end(); ++iter) {
                for (int i = 0; i != wordList.size(); i++)
                    if (!visited[i] && isTransformation(*iter, wordList[i])) {
                        nexts.insert(wordList[i]);
                        visited[i] = 1;
                    }
            }
            paths = move(nexts);
            length++;
            for (auto iter = paths.begin(); iter != paths.end(); ++iter)
                if (*iter == endWord)
                    return length + 1;
        }
        return 0;
    }
private:
    bool isTransformation(const string& s1, const string& s2) {
        int num = 0;
        for (int i = 0; i != s1.size(); ++i) {
            if (s1[i] != s2[i])
                num++;
            if (num > 1)
                break;
        }
        return num == 1;
    }
};
