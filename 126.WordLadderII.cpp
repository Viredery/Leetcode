class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> pathList;
        vector<string> path;
        map<string, vector<string>> wordMap;
        constructStringMap(beginWord, endWord, wordList, wordMap);
        backTrace(endWord, beginWord, wordMap, pathList, path);
        return pathList;
    }
private:
    void constructStringMap(string beginWord, string endWord,
                            vector<string>& wordList, map<string, vector<string>>& wordMap) {
        unordered_set<string> visited, unvisited(wordList.begin(), wordList.end());
        queue<string> que;
        unvisited.erase(beginWord);
        que.push(beginWord);
        bool flag = false;
        int currNum = 1, nextNum = 0;
        while (!que.empty()) {
            string currWord = que.front();
            que.pop();
            currNum--;
            string word(currWord);
            for (int i = 0; i != word.size(); i++) {
                char letter = word[i];
                for (int j = 0; j != 26; j++) {
                    word[i] = 'a' + j;
                    auto iter = unvisited.find(word);
                    if (iter != unvisited.end()) {
                        if (visited.find(word) == visited.end()) {
                            visited.insert(word);
                            que.push(word);
                            nextNum++;
                        }
                        if (wordMap.find(word) != wordMap.end()) {
                            wordMap[word].push_back(currWord);
                        } else {
                            wordMap[word] = {currWord};
                        }
                        if (currWord == endWord)
                            flag = true;
                    }
                }
                word[i] = letter;
            }
            if (currNum == 0) {
                if (flag == true)
                    return;
                currNum = nextNum;
                nextNum = 0;
                for (auto iter = visited.begin(); iter != visited.end(); iter++)
                    unvisited.erase(*iter);
                visited.clear();
            }
        }
    }
    void backTrace(string word, string aimWord, map<string, vector<string>>& wordMap,
                   vector<vector<string>>& pathList, vector<string>& path) {
        if (word == aimWord) {
            path.push_back(word);
            pathList.push_back(vector<string>(path.rbegin(), path.rend()));
            path.pop_back();
            return;
        }
        path.push_back(word);
        if (wordMap.find(word) != wordMap.end())
            for (auto s : wordMap[word])
                backTrace(s, aimWord, wordMap, pathList, path);
        path.pop_back();
    }
};
