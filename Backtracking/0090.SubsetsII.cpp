class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> subsets;
        std::vector<int> cur_subset;
        Backtracking(nums, 0, &cur_subset, &subsets);
        return subsets;
    }
private:
    void Backtracking(const std::vector<int>& nums, 
                      int start,
                      std::vector<int>* cur_subset,
                      std::vector<std::vector<int>>* subsets) const {
        if (start == nums.size()) {
            subsets->emplace_back(cur_subset->begin(), cur_subset->end());
            return;
        }
        cur_subset->push_back(nums[start]);
        Backtracking(nums, start + 1, cur_subset, subsets);
        cur_subset->pop_back();
        int next = start + 1;
        while (next != nums.size() && nums[next] == nums[start]) {
            next++;
        }
        Backtracking(nums, next, cur_subset, subsets);
    }
};
