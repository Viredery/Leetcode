class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        int maxSquare = 0;
        vector<vector<int>> stat(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i != n; i++)
            for (int j = 0; j != m; j++)
                if (matrix[i][j] == '1') {
                    stat[i+1][j+1] = min(stat[i][j+1], min(stat[i+1][j], stat[i][j])) + 1;
                    maxSquare = max(maxSquare, stat[i+1][j+1]*stat[i+1][j+1]);
                }
        return maxSquare;
    }
};