class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        else if (matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> left_corner(n, 0), right_corner(n, n), height_corner(n, 0);
        int maxRect = 0;
        for (int i = 0; i != m; i++) {
            int left_cur = 0, right_cur = n;
            for (int j = 0; j != n; j++) 
                height_corner[j] = matrix[i][j] == '1' ? 
                        height_corner[j] + 1 : 0;
            for (int j = 0; j != n; j++) {
                if (matrix[i][j] == '1')
                    left_corner[j] = std::max(left_corner[j], left_cur);
                else {
                    left_cur = j + 1;
                    left_corner[j] = 0;
                }
            }
            for (int j = n-1; j >= 0; j--) {
                if (matrix[i][j] == '1')
                    right_corner[j] = std::min(right_corner[j], right_cur);
                else {
                    right_cur = j;
                    right_corner[j] = n;
                }
            }
            
            for (int j = 0; j != n; j++)
                maxRect = max(
                    maxRect, 
                    (right_corner[j] - left_corner[j]) * height_corner[j]
                );
        }
        return maxRect;
    }
};
