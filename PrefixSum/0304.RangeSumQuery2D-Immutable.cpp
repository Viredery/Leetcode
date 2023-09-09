class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix.front().size();
        partial_sums = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                partial_sums[i + 1][j + 1] = 
                        matrix[i][j] + partial_sums[i + 1][j] + partial_sums[i][j + 1] - partial_sums[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return partial_sums[row2 + 1][col2 + 1] - partial_sums[row2 + 1][col1] -
                        partial_sums[row1][col2 + 1] + partial_sums[row1][col1];
    }
private:
    std::vector<std::vector<int>> partial_sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
