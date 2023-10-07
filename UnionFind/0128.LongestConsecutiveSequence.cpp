class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> indexes;
        DisjointSetUnion dsu{nums.size()};
        for (int idx = 0; idx != nums.size(); ++idx) {
            if (indexes.count(nums[idx])) {
                continue;
            }
            indexes.emplace(nums[idx], idx);
            if (indexes.count(nums[idx] - 1)) {
                const int other_idx = indexes[nums[idx] - 1];
                if (dsu.Find(idx) != dsu.Find(other_idx)) {
                    dsu.Union(idx, other_idx);
                }
            }
            if (indexes.count(nums[idx] + 1)) {
                const int other_idx = indexes[nums[idx] + 1];
                if (dsu.Find(idx) != dsu.Find(other_idx)) {
                    dsu.Union(idx, other_idx);
                }
            }
        }
        int max_num = 0;
        std::unordered_map<int, int> sequence_sizes;
        for (int idx = 0; idx != dsu.parents.size(); ++idx) {
            max_num = std::max(max_num, ++sequence_sizes[dsu.Find(idx)]);
        }
        return max_num;
    }
private:
    struct DisjointSetUnion {
        DisjointSetUnion(size_t size) : parents(size, 0) {
            std::iota(parents.begin(), parents.end(), 0);
        }

        int Find(int index) {
            if (parents[index] != index) {
                parents[index] = Find(parents[index]);
            }
            return parents[index];
        }

        void Union(int index, int other_index) {
            parents[Find(index)] = Find(other_index);
        }

        std::vector<int> parents;
    };
};
