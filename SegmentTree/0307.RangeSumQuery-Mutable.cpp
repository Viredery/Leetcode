class NumArray {
public:
    NumArray(vector<int>& nums) : st(nums) {
        
    }
    
    void update(int index, int val) {
        st.Update(index, val);
    }
    
    int sumRange(int left, int right) {
        return st.SumRange(left, right);
    }
private:
    struct SegmentTree {
        SegmentTree(const std::vector<int>& nums) 
                : tree(2 * nums.size(), 0) {
            for (int i = nums.size() - 1; i >= 0; --i) {
                tree[i + nums.size()] = nums[i];
            }
            for (int i = nums.size() - 1; i >= 0; --i) {
                tree[i] = tree[i * 2] + tree[i * 2 + 1];
            }
        }
        
        void Update(int pos, int new_val) {
            const int n = tree.size() / 2;
            const int diff = new_val - tree[n + pos];
            for (int i = n + pos; i >= 1; i /= 2) {
                tree[i] += diff;
            }
        }

        int SumRange(int left, int right) {
            int sum = 0;
            const int n = tree.size() / 2;
            for (int i = left + n, j = right + n; i <= j; i /= 2, j /= 2) {
                if (i % 2 == 1) {
                    sum += tree[i++];
                }
                if (j % 2 == 0) {
                    sum += tree[j--];
                }
            }
            return sum;
        }

        std::vector<int> tree;
    };

    SegmentTree st;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
