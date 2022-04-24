class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return std::max(rob(nums, 0, nums.size() - 1),
                        rob(nums, 1, nums.size()));
    }
private:
    int rob(const vector<int>& nums, int start, int end) {
        std::vector<int> max_amount_with_robbing(nums.size() + 1, 0);
        std::vector<int> max_amount_wo_robbing(nums.size() + 1, 0);
        for (int i = start; i < end; ++i) {
            max_amount_with_robbing[i + 1] = nums[i] + max_amount_wo_robbing[i];
            max_amount_wo_robbing[i + 1] = std::max(max_amount_with_robbing[i],
                                                    max_amount_wo_robbing[i]);
        }
        return std::max(max_amount_with_robbing[end], max_amount_wo_robbing[end]);
    }
};
