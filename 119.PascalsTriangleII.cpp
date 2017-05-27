class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex + 1;
        vector<int> res(n, 0);
        res[0] = 1;
        for (int i = 1; i != n; i++)
            for (int j = i; j != 0; j--)
                res[j] += res[j-1];
        return res;
    }
};
