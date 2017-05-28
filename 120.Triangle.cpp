class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        vector<vector<int>> minArr;
        minArr.push_back({triangle[0][0]});
        for (int i = 1; i != triangle.size(); i++) {
            vector<int> curMinArr(triangle[i].size(), 0);
            for (int j = 0; j != triangle[i].size(); j++) {
                if (j == 0)
                    curMinArr[j] = minArr[i-1][j] + triangle[i][j];
                else if (j == triangle[i].size() - 1)
                    curMinArr[j] = minArr[i-1][triangle[i].size() - 2] + triangle[i][j];
                else
                    curMinArr[j] = min(minArr[i-1][j-1], minArr[i-1][j])  + triangle[i][j];
            }
            minArr.push_back(curMinArr);
        }
        return *min_element(minArr.back().begin(), minArr.back().end());
    }
};
