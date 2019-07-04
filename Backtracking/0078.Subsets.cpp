class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        subsets(nums, 0, cur, res);
        return res;
    }
private:
    void subsets(vector<int>& nums, 
                 int i, 
                 vector<int>& cur, 
                 vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        subsets(nums, i+1, cur, res);
        cur.pop_back();
        subsets(nums, i+1, cur, res);
    }
};
