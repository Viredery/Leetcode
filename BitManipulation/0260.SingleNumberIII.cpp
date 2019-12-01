class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (auto num : nums)
            x ^= num;
        int bit = x & -x;
        int num1 = 0, num2 = 0;
        for (auto num : nums) {
            if (num & bit)
                num1 ^= num;
            else
                num2 ^= num;
        }
        return {num1, num2};
    }
};
