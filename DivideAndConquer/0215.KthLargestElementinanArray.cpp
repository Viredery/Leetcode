class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size() - 1, k);
    }
private:
    int findKthLargest(vector<int>& nums, int left, int right, int k) {
        const int pivot = nums[right];
        int next_larger_pos = left;
        for (int i = left; i < right; ++i) {
            if (nums[i] > pivot) {
                std::swap(nums[next_larger_pos++], nums[i]);
            }
        }
        std::swap(nums[next_larger_pos], nums[right]);
        if (next_larger_pos == k - 1) {
            return nums[k - 1];
        }
        return next_larger_pos < k - 1 ? findKthLargest(nums, next_larger_pos + 1, right, k)
                                       : findKthLargest(nums, left, next_larger_pos - 1, k);
    }
};
