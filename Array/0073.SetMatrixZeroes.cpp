class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // mark
        bool mark_row = matrix[0][0] == 0, mark_col = matrix[0][0] == 0;
        for (int i = 0; i != m; i++)
            for (int j = 0; j != n; j++)
                if (matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                    if (i == 0)
                        mark_row = true;
                    if (j == 0)
                        mark_col = true;
                }
        // set
        for (int i = 1; i != m; i++)
            if (matrix[i][0] == 0)
                for (int j = 1; j != n; j++)
                    matrix[i][j] = 0;
        for (int j = 1; j != n; j++)
            if (matrix[0][j] == 0)
                for (int i = 1; i != m; i++)
                    matrix[i][j] = 0;
        for (int i = 1; mark_col && i != m; i++)
            matrix[i][0] = 0;
        for (int j = 1; mark_row && j != n; j++)
            matrix[0][j] = 0;
    }
};
