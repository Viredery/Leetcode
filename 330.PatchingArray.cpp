class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1, pos = 0, res = 0;
        while (miss <= n) {
            if (pos < nums.size() && nums[pos] <= miss) {
                miss += nums[pos];
                pos++;
            } else {
                miss += miss;
                res++;
            }
        }
        return res;
    }
};
