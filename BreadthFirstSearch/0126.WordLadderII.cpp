class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<string, set<string>> graph;
        for (string& word : wordList) {
            for (int i = 0; i != word.size(); i++)
                graph[word.substr(0, i) + "*" + word.substr(i+1)].insert(word);
        }
        vector<vector<string>> ans;
        queue<vector<string>> paths;
        set<string> visited, levelVisited;
        int curLen = 1, minFindLen = INT_MAX;
        paths.push({beginWord});
        
        while (!paths.empty()) {
            vector<string> path = paths.front();
            paths.pop();
            if (path.size() >= minFindLen)
                break;
            if (path.size() > curLen) {
                for (auto iter = levelVisited.begin(); iter != levelVisited.end(); ++iter)
                    visited.insert(*iter);
                levelVisited.clear();
                curLen = path.size();
                
            }
            string key = path.back();
            for (int i = 0; i != key.size(); i++) {
                set<string> nexts = graph[key.substr(0, i) + "*" + key.substr(i+1)];
                for (auto iter = nexts.begin(); iter != nexts.end(); ++iter) {
                    if (visited.find(*iter) != visited.end())
                        continue;
                    vector<string> newPath = path;
                    newPath.push_back(*iter);
                    
                    if (*iter == endWord) {
                        minFindLen = newPath.size();
                        ans.push_back(move(newPath));
                    } else {
                        levelVisited.insert(*iter);
                        paths.push(move(newPath));
                    }
                }
            }
        }
        return ans;
    }
};


