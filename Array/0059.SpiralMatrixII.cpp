class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));      
        int level = (n + 1) / 2;
        int startNum = 1;
        for (int i = 0; i != level; i++) {
            spiralMatrix(matrix, i, n, startNum);
            startNum += (n - 1 - 2 * i) * 4;
        }
        return matrix;
    }
    
private:
    void spiralMatrix(vector<vector<int>>& matrix, int level, int n, int startNum) {
        if (level == n - level - 1) {
            matrix[level][level] = startNum;
            return;
        }
        int start = level, end = n - level - 1;
        for (int i = start; i != end; i++)
            matrix[start][i] = startNum++;
        for (int i = start; i != end; i++)
            matrix[i][end] = startNum++;
        for (int i = end; i != start; i--)
            matrix[end][i] = startNum++;
        for (int i = end; i != start; i--)
            matrix[i][start] = startNum++;
    }
};
