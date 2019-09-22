class NumArray {
public:
    NumArray(vector<int>& nums) : segmentTree(nums.size()*2, 0) {
        n = nums.size();
        buildSegmentTree(nums);
    }
    
    void update(int i, int val) {
        int pos = n + i;
        int oldVal = segmentTree[pos];
        while (pos > 0) {
            segmentTree[pos] = segmentTree[pos] - oldVal + val;
            pos /= 2;
        }
    }
    
    int sumRange(int i, int j) {
        int l = n + i, r = n + j;
        int sum = 0;
        while (l <= r) {
            if ((l % 2) == 1)
                sum += segmentTree[l++];
            if ((r % 2) == 0)
                sum += segmentTree[r--];
            l /= 2;
            r /= 2;
        }
        return sum;
    }
private:
    void buildSegmentTree(vector<int>& nums) {
        for (int i = n, j = 0; i != n*2; ++i, ++j)
            segmentTree[i] = nums[j];
        for (int i = n-1; i > 0; --i)
            segmentTree[i] = segmentTree[i*2] + segmentTree[i*2+1];
    }
    vector<int> segmentTree;
    int n;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
