class NumArray {
public:
    NumArray(vector<int> nums) : tree(nums.size() * 2, 0) {
        if (nums.empty())
            return;
        for (int j = 0; j != nums.size(); j++)
            tree[nums.size() + j] = nums[j];
        for (int j = nums.size() - 1; j > 0; j--)
            tree[j] = tree[j * 2] + tree[j * 2 + 1];
    }
    
    void update(int i, int val) {
        i = i + tree.size() / 2;
        tree[i] = val;
        i /= 2;
        while (i > 0) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
            i /= 2;
        }
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        i = i + tree.size() / 2;
        j = j + tree.size() / 2;
        while (i <= j) {
            if (i % 2 == 1)
                sum += tree[i++];
            if (j % 2 == 0)
                sum += tree[j--];
            i /= 2;
            j /= 2;
        }
        return sum;
    }
private:
    vector<int> tree;
};