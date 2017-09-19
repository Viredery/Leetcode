class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        return max(robTwoPoints(nums, 2, nums.size()-1) + nums[0],
                   robTwoPoints(nums, 1, nums.size()));
    }
private:
    int robTwoPoints(vector<int>& nums, int l, int r) {
        vector<vector<int>> stat(2, vector<int>(nums.size()+1, 0));
        for (int i = l; i < r; i++) {
            stat[0][i+1] = max(stat[0][i], stat[1][i]);
            stat[1][i+1] = nums[i] + stat[0][i];
        }
        return max(stat[0][r], stat[1][r]);        
    }
};