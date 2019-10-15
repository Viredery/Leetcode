class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;
        int m = board.size(), n = board[0].size();
        UnionFind uf(m, n);
        for (int i = 0; i != m; i++)
            for (int j = 0; j != n; j++) {
                if (i == 0 || j == 0 || i == m-1 || j == n-1)
                    uf.connect(i*n+j, m*n);
                if (board[i][j] == 'X')
                    continue;
                if (i+1 != m && board[i+1][j] == 'O')
                    uf.connect(i*n+j, (i+1)*n+j);
                if (j+1 != n && board[i][j+1] == 'O')
                    uf.connect(i*n+j, i*n+j+1);
            }
        for (int i = 0; i != m; i++)
            for (int j = 0; j != n; j++)
                if (!uf.connected(i*n+j, m*n))
                    board[i][j] = 'X';
    }
private:
    class UnionFind {
    public:
        UnionFind(int m, int n) : uf(m*n+1, 0), depth(m*n+1, 0) {
            for (int i = 0; i != uf.size(); ++i)
                uf[i] = i;
        }
        bool connected(int pos1, int pos2) {
            return find(pos1) == find(pos2);
        }
        void connect(int pos1, int pos2) {
            pos1 = find(pos1);
            pos2 = find(pos2);
            if (pos1 == pos2)
                return;
            if (depth[pos1] > depth[pos2])
                uf[pos2] = pos1;
            else if (depth[pos1] < depth[pos2])
                uf[pos1] = pos2;
            else {
                uf[pos2] = pos1;
                depth[pos1]++;
            }
        }
        int find(int pos) {
            while (uf[pos] != pos)
                pos = uf[pos];
            return pos;
        }
    private:
        vector<int> uf;
        vector<int> depth;
    };
};
