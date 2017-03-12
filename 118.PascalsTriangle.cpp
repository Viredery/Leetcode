class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (0 == numRows)
            return {};
        vector<vector<int>> res(1, {1});
        for (int i = 2; i <= numRows; i++) {
            vector<int> line(i, 1);
            for (int j = 1; j != i - 1; j++)
                line[j] = res.back()[j] + res.back()[j - 1];
            res.push_back(line);
        }
        return res;
    }
};