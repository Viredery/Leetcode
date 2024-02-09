class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest_sum = 2 * 10e4 + 1;
        std::ranges::sort(nums);
        for (int i = 0; i < nums.size() - 2; ++i) {
            twoSumClosest(nums, i + 1, nums.size() - 1, target, nums[i], &closest_sum);
        }
        return closest_sum;
    }
private:
    void twoSumClosest(vector<int>& nums, int left, int right, int target, int first_num, int* closest_sum) {
        while (left < right) {
            const int sum = first_num + nums[left] + nums[right];
            if (std::abs(sum - target) < std::abs(*closest_sum - target)) {
                *closest_sum = sum;
            }
            if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }
};
