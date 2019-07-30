class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());
        vector<int> path;
        dfs(nums, target, 0, 0, 0, path, res);
        return res;
    }
private:
    void dfs(vector<int>& nums, int target, int pos, int count, int sum, 
             vector<int>& path, vector<vector<int>>& res) {
        if (count == 4) {
            if (target == sum)
                res.push_back(path);
            return;
        }
        for (int i = pos; i != nums.size(); i++) {
            if (i != pos && nums[i] == nums[i - 1])
                continue;
            if (sum + nums[i] + (3 - count) * nums[nums.size() - 1] < target)
                continue;
            if (sum + (4 - count) * nums[i] > target)
                break;
            path.push_back(nums[i]);
            dfs(nums, target, i+1, count+1, sum+nums[i], path, res);
            path.pop_back();
        }
    }
};
