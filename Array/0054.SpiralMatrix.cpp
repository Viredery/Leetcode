class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        vector<int> res;
        int h = (matrix.size() + 1) / 2;
        int w = (matrix[0].size() + 1) / 2;
        int spiralNum = std::min(h, w);
        for (int i = 0; i != spiralNum; i++) {
            spiralLevel(matrix, i, res);
        }
        return res;
    }
private:
    void spiralLevel(vector<vector<int>>& matrix, int level, vector<int>& res) {
        int h = matrix.size(), w = matrix[0].size();
        if (level == w - level - 1 && level == h - level - 1) {
            res.push_back(matrix[level][level]);
            return;
        }
        if (level == w - level - 1 || level == h - level - 1) {
            if (level == w - level - 1) {
                for (int i = level; i != h - level; i++)
                    res.push_back(matrix[i][level]);
            } else {
                for (int i = level; i != w - level; i++)
                    res.push_back(matrix[level][i]);
            }
            return;
        }
        
        for (int i = level; i != w - level - 1; i++)
            res.push_back(matrix[level][i]);
        for (int i = level; i != h - level - 1; i++)
            res.push_back(matrix[i][w - level - 1]);
        for (int i = w - level - 1; i != level; i--)
            res.push_back(matrix[h - level - 1][i]);
        for (int i = h - level - 1; i != level; i--)
            res.push_back(matrix[i][level]);
    }
};
