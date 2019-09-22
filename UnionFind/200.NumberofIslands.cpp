class UnionFind {
public:
    UnionFind(int s, int c) : arr(s, 0), count(c) {
        for (int i = 0; i != s; i++)
            arr[i] = i;
    }
    int getCount() {
        return count;
    }
    void unionTwo(int p, int q) {
        tuple<int, int> pTuple = find(p);
        tuple<int, int> qTuple = find(q);
        if (get<0>(pTuple) == get<0>(qTuple))
            return;
        get<1>(pTuple) < get<1>(qTuple) ? arr[get<0>(pTuple)] = get<0>(qTuple)
                : arr[get<0>(qTuple)] = get<0>(pTuple);
        --count;
    }
private:
    vector<int> arr;
    int count;
    tuple<int, int> find(int p) {
        int depth = 0;
        while (p != arr[p]) {
            p = arr[p];
            ++depth;
        }
        return {p, depth};
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        
        int count = 0;
        for (int i = 0; i != m; i++)
            for (int j = 0; j != n; j++)
                if ('1' == grid[i][j])
                    count += 1;
        UnionFind uf(m*n, count);
        for (int i = 0; i != m; i++)
            for (int j = 0; j != n; j++) {
                if ('0' == grid[i][j])
                    continue;
                if (j+1 < n && '1' == grid[i][j+1])
                    uf.unionTwo(i*n+j, i*n+j+1);
                if (i+1 < m && '1' == grid[i+1][j])
                    uf.unionTwo(i*n+j, i*n+j+n);
            }
        return uf.getCount();
    }
};


