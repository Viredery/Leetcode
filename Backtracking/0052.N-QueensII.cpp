class Solution {
public:
    int totalNQueens(int n) {
        sum = 0;
        cols = vector<bool>(n);
        slashes = vector<bool>(2 * n - 1);
        backslashes = vector<bool>(2 * n - 1);
        backtracking(n, 0);
        return sum;
    }
private:
    int sum;
    vector<bool> cols, slashes, backslashes;
    
    void backtracking(const int n, int pos) {
        if (pos == n) {
            sum++;
            return;
        }
        for (int i = 0; i != n; i++) {
            if (cols[i] || slashes[i+pos] || backslashes[i-pos+n-1])
                continue;
            cols[i] = slashes[i+pos] = backslashes[i-pos+n-1] = true;
            backtracking(n, pos+1);
            cols[i] = slashes[i+pos] = backslashes[i-pos+n-1] = false;
        }
    }
};
