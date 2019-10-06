class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0)
            return {};
        vector<int> lvl(rowIndex+1, 0);
        lvl[0] = 1;
        for (int i = 1; i != rowIndex+1; i++)
            for (int j = i; j != 0; j--)
                lvl[j] += lvl[j-1];
        return lvl;
    }
};
