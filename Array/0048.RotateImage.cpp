class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rotate_num = matrix.size() / 2;
        for (int i = 0; i != rotate_num; i++)
            rotate_level(matrix, i);
    }
private:
    void rotate_level(vector<vector<int>>& matrix, int level) {
        int start = level, end = matrix.size() - 1 - level;
        int size = end - start;
        for (int i = 0; i != size; i++) {
            int tmp                = matrix[start][start+i];
            matrix[start][start+i] = matrix[end-i][start];
            matrix[end-i][start]   = matrix[end][end-i];
            matrix[end][end-i]     = matrix[start+i][end];
            matrix[start+i][end]   = tmp;
        }
    }
};
