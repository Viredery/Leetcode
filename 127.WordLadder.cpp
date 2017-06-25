class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord.size() != endWord.size() || beginWord.empty())
            return 0;
        queue<string> que;
        que.push(beginWord);
        int minLength = 1;
        while (!que.empty()) {
            int queNum = que.size();
            for (int _ = 0; _ != queNum; _++) {
                string currWord = que.front();
                que.pop();
                if (currWord == endWord)
                    return minLength;
                getNextWord(currWord, wordList, que);
            }
            minLength++;
        }
        return 0;
    }
private:
    void getNextWord(string currWord, vector<string>& wordList, queue<string>& que) {
        for (int i = 0; i != wordList.size(); i++) {
            if (wordList[i].empty() || currWord.size() != wordList[i].size())
                continue;
            int distanceHamming = 0;
            for (int j = 0; j != currWord.size(); j++) {
                if (currWord[j] == wordList[i][j])
                    continue;
                distanceHamming++;
            }
            if (distanceHamming == 1) {
                que.push(wordList[i]);
                wordList[i] = "";
            }
        }
    }
};