class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int num_subarrays = 0;
        int left = 0;
        long product_res = 1;
        for (int i = 0; i != nums.size(); ++i) {
            product_res *= nums[i];
            while (product_res >= k && left <= i) {
                product_res /= nums[left++];
            }
            num_subarrays += i - left + 1;
        }
        return num_subarrays;
    }
};
