class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        uf = vector<int>(edges.size()+1);
        std::iota(uf.begin(), uf.end(), 0);
        
        for (auto& edge : edges) {
            if (find(edge[0]) == find(edge[1]))
                return vector<int>(edge);
            uf[find(edge[0])] = find(edge[1]);
        }
        return {-1, -1};
    }
private:
    vector<int> uf;

    int find(int x) {
        if (x != uf[x])
            x = find(uf[x]);
        return x;
    }
};
