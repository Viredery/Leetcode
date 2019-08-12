class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> status;
        dp(n, status, res);
        return res; 
    }
private:
    void dp(const int n, vector<int>& status, vector<vector<string>>& res) {
        if (status.size() == n) {
            vector<string> cur;
            for (int i = 0; i != n; i++) {
                cur.push_back(string(n, '.'));
                cur[i][status[i]] = 'Q';
            }
            res.push_back(move(cur));
            return;
        }
        for (int i = 0; i != n; i++) {
            if (!check(status, n, i))
                continue;
            status.push_back(i);
            dp(n, status, res);
            status.pop_back();
        }
    }
    bool check(vector<int>& status, int n, int pos) {
        for (int i = 0; i < status.size(); i++)
            if (status[i] == pos)
                return false;
        for (int i = 1; pos - i >= 0 && status.size() >= i; i++)
            if (status[status.size()-i] == pos - i)
                 return false;
        for (int i = 1; pos + i < n && status.size() >= i; i++)
            if (status[status.size()-i] == pos + i)
                 return false;
        return true;
    }
};
