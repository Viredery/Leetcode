class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> all_subsets;
        std::vector<int> cur_subset;
        backtracking(nums, 0, &cur_subset, &all_subsets);
        return all_subsets;
    }
private:
    void backtracking(const std::vector<int>& nums, 
                      int start_pos, 
                      std::vector<int>* cur_subset,
                      std::vector<std::vector<int>>* all_subsets) {
        if (start_pos == nums.size()) {
            all_subsets->push_back(std::vector<int>{cur_subset->begin(), cur_subset->end()});
            return;
        }
        cur_subset->push_back(nums[start_pos]);
        backtracking(nums, start_pos + 1, cur_subset, all_subsets);
        cur_subset->pop_back();
        backtracking(nums, start_pos + 1, cur_subset, all_subsets);
    }
};
