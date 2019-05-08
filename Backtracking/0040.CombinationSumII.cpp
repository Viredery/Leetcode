class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, 0, target, cur, res);
        return res;
    }
    
private:
    void backtracking(vector<int>& candidates, int pos, int target, 
                      vector<int>& cur, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        int i = pos;
        
        while (i != candidates.size()) {
            if (candidates[i] <= target) {
                cur.push_back(candidates[i]);
                backtracking(candidates, i+1, target-candidates[i], cur, res);
                cur.pop_back();
            }
            while (i + 1 != candidates.size() && candidates[i+1] == candidates[i])
                    i++;
            i++;
        }
    }
};
