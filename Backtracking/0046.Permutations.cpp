class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> permutations;
        std::vector<int> current;
        std::vector<bool> visited(nums.size(), false);
        backtracking(nums, &visited, &current, &permutations);
        return permutations;
    }
private:
    void backtracking(const vector<int>& nums,
                      std::vector<bool>* visited,
                      std::vector<int>* current,
                      std::vector<std::vector<int>>* permutations) const {
        if (current->size() == nums.size()) {
            permutations->emplace_back(current->begin(), current->end());
            return;
        }
        for (int i = 0; i != nums.size(); ++i) {
            if ((*visited)[i]) {
                continue;
            }
            current->push_back(nums[i]);
            (*visited)[i] = true;
            backtracking(nums, visited, current, permutations);
            current->pop_back();
            (*visited)[i] = false;
        }
    }
};
