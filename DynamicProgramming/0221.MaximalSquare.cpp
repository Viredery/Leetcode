class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        const int m = matrix.size();
        const int n = matrix[0].size();
        std::vector<std::vector<int>> sum(m+1, std::vector<int>(n+1, 0));
        int max_area = 0;
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (matrix[i][j] == '0') {
                    continue;
                }
                sum[i+1][j+1] = 1 + std::min(
                    sum[i][j], std::min(sum[i+1][j], sum[i][j+1]));
                max_area = std::max(max_area, sum[i+1][j+1] * sum[i+1][j+1]);
            }
        }
        return max_area;
    }
};
