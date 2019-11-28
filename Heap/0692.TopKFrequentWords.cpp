class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> hash;
        for (auto word : words)
            hash[word]++;

        priority_queue<pair<int, string>> que;
        
        for (auto item : hash) {
            que.push({-item.second, item.first});
            if (que.size() > k) {
                que.pop();
            }
        }
        vector<string> res(k);
        while (!que.empty()) {
            res[--k] = que.top().second;
            que.pop();
        }

        return res;
    }
