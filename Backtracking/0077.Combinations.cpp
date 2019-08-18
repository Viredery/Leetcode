class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        backtracking(n, k, 1, cur, res);
        return res;
    }
private:
    void backtracking(int n, int k, int pos,
                      vector<int>& cur, vector<vector<int>>& res) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }
        if (pos > n)
            return;
        
        cur.push_back(pos);
        backtracking(n, k, pos+1, cur, res);
        cur.pop_back();
        
        backtracking(n, k, pos+1, cur, res);
    }
};
