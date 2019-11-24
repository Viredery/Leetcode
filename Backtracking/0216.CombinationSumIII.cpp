class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(1, 0, k, n);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int start, int sum, int k, int n) {
        if (sum == n && k == 0) {
            res.push_back(path);
            return;
        }
        if (sum > n || k == 0 || start == 10)
            return;
        
        backtracking(start + 1, sum, k, n);
        path.push_back(start);
        sum += start;
        backtracking(start + 1, sum, k - 1, n);
        path.pop_back();
        sum -= start;
    }
};
