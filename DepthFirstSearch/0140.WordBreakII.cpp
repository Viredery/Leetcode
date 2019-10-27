class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> dp(s.size() + 1, vector<int>());
        priority_queue<int> next;
        next.push(0);
        while (!next.empty()) {
            int i = next.top();
            next.pop();
            for (int j = 0; j != wordDict.size(); j++) {
                int n = wordDict[j].size();
                if (i + n > s.size() || 
                    s.substr(i, n) != wordDict[j] ||
                    find(dp[i+n].begin(), dp[i+n].end(), j) != dp[i+n].end())
                    continue;
                dp[i+n].push_back(j);
                if (i + n != s.size())
                    next.push(i + wordDict[j].size());
                
            }
        }

        vector<string> res;
        vector<int> cur;
        backtracking(dp, s.size(), wordDict, cur, res);
        return res;
    }
private:
    void backtracking(vector<vector<int>>& dp, int pos, vector<string>& wordDict, 
                      vector<int>& cur, vector<string>& res) {
        if (pos == 0) {
            string word = "";
            for (int j = cur.size()-1; j >= 0; j--) {
                word += wordDict[cur[j]];
                if (j - 1 >= 0)
                    word += " ";
            }
            res.push_back(word);
            return;
        }
        if (dp[pos].empty())
            return;
        for (int i = 0; i != dp[pos].size(); i++) {
            cur.push_back(dp[pos][i]);
            backtracking(dp, pos - wordDict[dp[pos][i]].size(), wordDict, cur, res);
            cur.pop_back();
        }
    }
};
