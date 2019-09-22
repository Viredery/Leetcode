class NumArray {
public:
    NumArray(vector<int>& nums) : nums(nums), BITree(nums.size()+1, 0) {
        n = nums.size();
        for (int i = 0; i < n; i++)
            initValue(i+1, nums[i]);
    }
    
    void update(int i, int val) {
        int diff = val - nums[i];
        nums[i] = val;
        initValue(i+1, diff);
    }
    
    int sumRange(int i, int j) {
        return sumRange(j+1) - sumRange(i);
    }
private:
    void initValue(int i, int val) {
        while (i <= n) {
            BITree[i] += val;
            i += (i & -i);
        }
    }
    
    int sumRange(int i) {
        int sum = 0;
        while (i > 0) {
            sum += BITree[i];
            i -= (i & -i);
        }
        return sum;
    }
    
    vector<int> BITree;
    vector<int>& nums;
    int n;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
