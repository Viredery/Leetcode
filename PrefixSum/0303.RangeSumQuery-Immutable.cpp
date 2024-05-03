class NumArray {
public:
    NumArray(vector<int>& nums) : prefix_sums(nums.size() + 1, 0) {
        for (int i = 0; i != nums.size(); ++i) {
            prefix_sums[i + 1] = prefix_sums[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix_sums[right + 1] - prefix_sums[left];
    }
private:
    std::vector<int> prefix_sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
