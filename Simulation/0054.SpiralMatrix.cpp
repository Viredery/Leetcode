class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {};
        vector<int> res;
        int y0 = 0, y1 = matrix.size() - 1;
        int x0 = 0, x1 = matrix[0].size() - 1;
        
        while (x0 <= x1 && y0 <= y1) {
            for (int i = x0; i <= x1; i++)
                res.push_back(matrix[y0][i]);
            for (int i = y0 + 1; i <= y1; i++)
                res.push_back(matrix[i][x1]);
            if (x0 < x1 && y0 < y1) {
                for (int i = x1 - 1; i >= x0; i--)
                    res.push_back(matrix[y1][i]);
                for (int i = y1 - 1; i > y0; i--)
                    res.push_back(matrix[i][x0]);
            }
            x0++, x1--;
            y0++, y1--;
        }
        
        return res;
    }

};
