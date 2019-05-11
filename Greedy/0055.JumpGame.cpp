class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = nums.size() - 2;
        bool reachable = true;
        while (pos >= 0) {
            if (nums[pos] != 0) { 
                pos--;
                continue;
            }
            reachable = false;
            int dis = 0;
            while (pos >= 0 && nums[pos] <= dis) {
                pos--;
                dis++;
            }
            if (pos >= 0 && nums[pos] > dis)
                reachable = true;       
        }
        return reachable;
    }
};
