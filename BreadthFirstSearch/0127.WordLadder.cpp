class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int length = 0;
        map<string, set<string>> graph;
        for (string& word : wordList) {
            for (int i = 0; i != word.size(); i++)
                graph[word.substr(0, i) + "*" + word.substr(i+1)].insert(word);
        }
        queue<tuple<string, int>> que;
        set<string> visited;
        que.push({beginWord, 1});
        visited.insert(beginWord);
        while (!que.empty()) {
            auto node = que.front();
            string key = get<0>(node);
            que.pop();
            for (int i = 0; i != key.size(); i++) {
                set<string> nexts = graph[key.substr(0, i) + "*" + key.substr(i+1)];
                for (auto iter = nexts.begin(); iter != nexts.end(); ++iter) {
                    if (*iter == endWord)
                        return get<1>(node) + 1;
                    if (visited.find(*iter) != visited.end())
                        continue;
                    visited.insert(*iter);
                    que.push({*iter, get<1>(node) + 1});
                }
            }
        }
        return 0;
    }
};
