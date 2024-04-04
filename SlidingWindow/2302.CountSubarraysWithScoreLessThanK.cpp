class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long num_subarrays = 0;
        int left = 0;
        long current_sum = 0;
        for (int i = 0; i != nums.size(); ++i) {
            current_sum += nums[i];
            while (current_sum * (i - left + 1) >= k && left <= i) {
                current_sum -= nums[left++];
            }
            num_subarrays += i - left + 1;
        }
        return num_subarrays;
    }
};
