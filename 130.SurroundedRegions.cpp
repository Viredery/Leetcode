class UnionFind {
public:
    UnionFind(int num): count(num) {
        id = new int[num];
        rate = new int[num];
        for (int i = 0; i != num; i++) {
            id[i] = i;
            rate[i] = 0;
        }
    }
    ~UnionFind() {
        delete[] id;
        delete[] rate;
    }
    int getCount() {
        return count;
    }
    int find(int p) {
        while (p != id[p]) {
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    void connect(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j)
            return;
        if (rate[i] < rate[j])
            id[i] = j;
        else if (rate[i] > rate[j])
            id[j] = i;
        else {
            id[j] = i;
            rate[i]++;
        }
        count--;
    }
private:
    int *id;
    int *rate;
    int count;
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        UnionFind uf(m * n + 1);
        
        for (int i = 0; i != m; i++) {
            for (int j = 0; j != n; j++) {
                if ((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O')
                    uf.connect(i*n+j, m*n);
                if (board[i][j] == 'O') {
                    if (i != m-1 && board[i+1][j] == 'O')
                        uf.connect(i*n+j, (i+1)*n+j);
                    if (j != n-1 && board[i][j+1] == 'O')
                        uf.connect(i*n+j, i*n+j+1);
                }
            }
        }
        for (int i = 0; i != m; i++) {
            for (int j = 0; j != n; j++) {
                if(!uf.connected(i*n+j, m*n))
                    board[i][j] = 'X';
            }
        }
    }
};