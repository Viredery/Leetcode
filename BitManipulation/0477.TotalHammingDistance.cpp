class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i != 32; i++) {
            int ones = 0, zeros = 0;
            for (auto num : nums) {
                if (num >> i & 1)
                    ones++;
                else
                    zeros++;
            }
            cnt += ones * zeros;
        }
        return cnt;
    }
};
