class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numberOfSubarraysAtMostK(nums, k) - numberOfSubarraysAtMostK(nums, k - 1);
    }
private:
    int numberOfSubarraysAtMostK(const vector<int>& nums, int k) const {
        int num_odd = 0;
        int num_subarray = 0;
        int left = 0;
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] & 1 == 1) {
                num_odd++;
            }
            while (num_odd > k) {
                if (nums[left] & 1 == 1) {
                    num_odd--;
                }
                left++;
            }
            num_subarray += i - left + 1;
        }
        return num_subarray;
    }
};
