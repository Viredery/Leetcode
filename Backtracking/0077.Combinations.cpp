class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> combinations;
        std::vector<int> current;
        backtracking(n, k, 1, &current, &combinations);
        return combinations;
    }
private:
    void backtracking(int n, 
                      int k, 
                      int start,
                      std::vector<int>* current, 
                      std::vector<std::vector<int>>* combinations) const {
        if (current->size() == k) {
            combinations->emplace_back(current->begin(), current->end());
            return;
        }
        if (start > n) {
            return;
        }
        for (int i = start; i <= n; ++i) {
            current->push_back(i);
            backtracking(n, k, i + 1, current, combinations);
            current->pop_back();
        }
    }
};
