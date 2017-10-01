class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        vector<int> nums(n);
        nums[0] = 1;
        int k1 = 0, k2 = 0, k3 = 0;
        for (int i = 1; i < n; i++) {
            nums[i] = min(nums[k1]*2, min(nums[k2]*3, nums[k3]*5));
            if (nums[i] == nums[k1]*2)
                k1++;
            if (nums[i] == nums[k2]*3)
                k2++;
            if (nums[i] == nums[k3]*5)
                k3++;            
        }
        return nums[n-1];
    }
};