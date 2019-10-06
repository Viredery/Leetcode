class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows <= 0)
            return {};
        vector<vector<int>> triangle = {{1}};
        for (int i = 2; i <= numRows; i++) {
            vector<int> lvl(i, 1);
            for (int j = 1; j < i-1; j++)
                lvl[j] = triangle.back()[j] + triangle.back()[j-1];
            triangle.push_back(std::move(lvl));
        }
        return triangle;
    }
};
