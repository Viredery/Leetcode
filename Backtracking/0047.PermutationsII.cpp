class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<int> valid(nums.size(), 1);
        sort(nums.begin(), nums.end());
        backtracking(nums, valid, cur, res);
        return res;
    }
    
private:
    void backtracking(vector<int>& nums, 
                      vector<int>& valid,
                      vector<int>& cur, 
                      vector<vector<int>>& res) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i != nums.size(); i++) {
            if (!valid[i])
                continue;
            if (i > 0 && nums[i] == nums[i-1] && valid[i-1])
                continue;
            cur.push_back(nums[i]);
            valid[i] = 0;
            backtracking(nums, valid, cur, res);
            valid[i] = 1;
            cur.pop_back();
        }
    }
};
