class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        std::sort(nums.begin(), nums.end());
        subsets(nums, 0, cur, res);
        return res;
    }
    
private:
    void subsets(
        vector<int>& nums, 
        int i, 
        vector<int>& cur, 
        vector<vector<int>>& res
    ) {
        if (i == nums.size()) {
            res.push_back(cur);
            return;
        }
        int cur_num = nums[i];
        cur.push_back(cur_num);
        subsets(nums, i+1, cur, res);
        cur.pop_back();
        int j = i + 1;
        while (j != nums.size() && nums[j] == cur_num)
            j++;
        subsets(nums, j, cur, res);
    }
};
