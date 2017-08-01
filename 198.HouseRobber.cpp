class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<vector<int>> stat(2, vector<int>(nums.size()+1, 0));
        for (int i = 0; i != nums.size(); i++) {
            stat[0][i+1] = max(stat[0][i], stat[1][i]);
            stat[1][i+1] = nums[i] + stat[0][i];
        }
        return max(stat[0][nums.size()], stat[1][nums.size()]);
    }
};