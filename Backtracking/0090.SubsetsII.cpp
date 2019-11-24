class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        std::sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return res;
    }
    
private:
    int n;
    
    vector<vector<int>> res;
    vector<int> cur;
    
    void backtracking(vector<int>& nums, int start) {
        if (start == n) {
            res.push_back(cur);
            return;
        }
    
        int val = nums[start];
        cur.push_back(val);
        backtracking(nums, start + 1);
        cur.pop_back();

        while (start < nums.size() && nums[start] == val)
            start++;
        backtracking(nums, start);
    }
};
