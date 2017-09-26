class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int mode_1, mode_2, times_1 = 0, times_2 = 0;
        for (auto num : nums) {
            if (mode_1 == num)
                times_1++;
            else if (mode_2 == num)
                times_2++;
            else if (times_1 == 0) {
                times_1++;
                mode_1 = num;
            } else if (times_2 == 0) {
                times_2++;
                mode_2 = num;
            } else {
                times_1--;
                times_2--;
            }
        }
        
        times_1 = 0, times_2 = 0;
        for (auto num : nums) {
            if (mode_1 == num)
                times_1++;
            else if (mode_2 == num)
                times_2++;
        }
        vector<int> res;
        if (times_1 > nums.size() / 3)
            res.push_back(mode_1);
        if (times_2 > nums.size() / 3)
            res.push_back(mode_2);
        return res;
    }
};