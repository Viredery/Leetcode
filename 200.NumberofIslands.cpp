class UnionFind {
public:
    UnionFind(int n, int count): valCount(count) {
        arr = new int[n];
        for (int i = 0; i != n; i++)
            arr[i] = i;
    }
    ~UnionFind() {
        delete [] arr;
    }
    void unionTwo(int p, int q) {
        tuple<int, int> pTuple = find(p);
        tuple<int, int> qTuple = find(q);
        if (get<0>(pTuple) == get<0>(qTuple))
            return;
        get<1>(pTuple) > get<1>(qTuple) ? arr[get<0>(qTuple)] = get<0>(pTuple)
                : arr[get<0>(pTuple)] = get<0>(qTuple);
        valCount--;
    }
    int count() {
        return valCount;
    }
private:
    int *arr;
    int valCount;
    tuple<int, int> find(int p) {
        int depth = 0;
        while (p != arr[p]) {
            p = arr[p];
            depth++;
        }
        return {p, depth};
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = (0 == m ? 0 : grid[0].size());
        int valCount = 0;
        for (int i = 0; i != m; i++)
            for (int j = 0; j != n; j++)
                if ('1' == grid[i][j])
                    valCount++;
        UnionFind uf(m * n, valCount);
        for (int i = 0; i != m; i++)
            for (int j = 0; j != n; j++) {
                if ('0' == grid[i][j])
                    continue;
                int pos = i * n + j;
                if (i + 1 != m && '1' == grid[i+1][j])
                    uf.unionTwo(pos, pos + n);
                if (j + 1 != n && '1' == grid[i][j+1])
                    uf.unionTwo(pos, pos + 1);
            }
        return uf.count();
    }
};