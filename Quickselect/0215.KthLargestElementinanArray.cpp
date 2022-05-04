class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size() - 1, k - 1);
    }
private:
    int findKthLargest(vector<int>& nums, int left, int right, int k) {
        int i = left, j = right - 1;
        while (i <= j) {
            while (i <= j && nums[i] > nums[right]) {
                i++;
            }
            while (i <= j && nums[j] <= nums[right]) {
                j--;
            }
            if (i <= j) {
                std::swap(nums[i++], nums[j--]);
            }
        }
        std::swap(nums[i], nums[right]);
        if (i == k) {
            return nums[i];
        }
        if (i < k) {
            return findKthLargest(nums, i + 1, right, k);
        }
        return findKthLargest(nums, left, i - 1, k);
    }
};
