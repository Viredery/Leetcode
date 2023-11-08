class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        for (auto& num : nums) {
            num += 1e4;
        }
        std::vector<int> counts(20001, 0);
        SegmentTree st(20001);
        std::vector<int> res(nums.size(), 0);
        st.Update(nums[nums.size() - 1], ++counts[nums[nums.size() - 1]]);
        for (int i = static_cast<int>(nums.size()) - 2; i >= 0; --i) {
            res[i] = st.SumRange(0, nums[i] - 1);
            st.Update(nums[i], ++counts[nums[i]]);
        }
        return res;
    }
private:
    struct SegmentTree {
        SegmentTree(int n) : tree(2 * n, 0) {}

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
};
