class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> nums(n, 0);
        nums[0] = 1;
        int k1 = 0, k2 = 0, k3 = 0;
        for (int i = 1; i != n; ++i) {
            nums[i] = std::min(nums[k1] * 2, std::min(nums[k2] * 3, nums[k3] * 5));
            if (nums[k1] * 2 <= nums[i]) {
                k1++;
            }
            if (nums[k2] * 3 <= nums[i]) {
                k2++;
            }
            if (nums[k3] * 5 <= nums[i]) {
                k3++;
            }
        }
        return nums.back();
    }
};
