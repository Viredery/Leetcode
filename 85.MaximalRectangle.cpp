class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        int maxRect = 0;
        std::vector<int> left(n, 0), right(n, n), height(n, 0);
        for (int i = 0; i != m; i++) {
            int curLeft = 0, curRight = n;
            for (int j = 0; j != n; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else height[j] = 0;
            }
            for (int j = 0; j != n; j++) {
                if (matrix[i][j] == '1')
                    left[j] = max(curLeft, left[j]);
                else {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }
            for (int j = n-1; j >= 0; j--) {
                if (matrix[i][j] == '1')
                    right[j] = min(curRight, right[j]);
                else {
                    right[j] = n;
                    curRight = j;
                }
            }
            for (int j = 0; j != n; j++)
                maxRect = max(maxRect, (right[j] - left[j]) * height[j]);
        }
        return maxRect;
    }
};
