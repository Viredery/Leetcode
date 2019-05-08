class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        backtracking(candidates, 0, target, res, cur);
        return res;
    }
private:
    void backtracking(vector<int>& candidates, int pos, int target,
                      vector<vector<int>>& res, vector<int>& cur) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = pos; i != candidates.size(); i++) {
            if (candidates[i] <= target) {
                cur.push_back(candidates[i]);
                backtracking(candidates, i, target-candidates[i], res, cur);
                cur.pop_back();
            }
        }
    }
};
