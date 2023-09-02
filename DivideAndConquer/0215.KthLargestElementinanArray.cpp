class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size() - 1, k - 1);
    }
private:
    int findKthLargest(vector<int>& nums, int left, int right, int k) {
        std::default_random_engine rand_gen;
        std::uniform_int_distribution distrib(left, right);
        std::swap(nums[right], nums[distrib(rand_gen)]);

        int wall = left;
        for (int i = left; i != right; ++i) {
            if (nums[i] >= nums[right]) {
                std::swap(nums[i], nums[wall++]);
            }
        }
        std::swap(nums[right], nums[wall]);
        if (wall == k) {
            return nums[wall];
        }
        return wall > k ? findKthLargest(nums, left, wall - 1, k) 
                        : findKthLargest(nums, wall + 1, right, k);
    }
};
