class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        isVisited = vector<bool>(n, false);
        backtracking(nums);
        return res;
    }
    
private:
    int n;
    
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> isVisited;
    void backtracking(vector<int>& nums) {
        if (path.size() == n) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i != n; i++) {
            if (isVisited[i])
                continue;
            isVisited[i] = true;
            path.push_back(nums[i]);
            backtracking(nums);
            path.pop_back();
            isVisited[i] = false;
        }
    }
};
