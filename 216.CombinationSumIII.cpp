class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> numbers;
        helper(k, 1, n, numbers, res);
        return res;
    }
private:
    void helper(int k, int start, int n, vector<int>& numbers, vector<vector<int>>& res) {
        if (n == 0 && k == 0) {
            res.push_back(numbers);
            return;
        }
        for (int i = start; i < 10; i++) {
            numbers.push_back(i);
            helper(k - 1, i + 1, n - i, numbers, res);
            numbers.pop_back();
        }
    }
};