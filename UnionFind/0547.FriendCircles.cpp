class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int res = M.size();

        uf = vector<int>(M.size());
        std::iota(uf.begin(), uf.end(), 0);
        
        for (int i = 0; i != M.size(); i++)
            for (int j = 0; j != i; j++)
                if (M[i][j] && find(i) != find(j)) {
                    uf[find(i)] = find(j);
                    res--;
                }
        
        return res;
    }

private:
    vector<int> uf;

    int find(int x) {
        if (uf[x] != x)
            x = find(uf[x]);
        return x;
    }
};
