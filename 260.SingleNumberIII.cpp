class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for (auto num : nums) {
            diff ^= num;
        }
        diff &= -diff;
        vector<int> res{0, 0};
        for (auto num : nums) {
            if ((num & diff) == 0)
                res[0] ^= num;
            else
                res[1] ^= num;
        }
        return res;
    }
};