class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int size = isConnected.size();
        int num_cicle = size;
        DisjointSetUnion dsu(num_cicle);
        for (int i = 0; i != size; ++i) {
            for (int j = i + 1; j != size; ++j) {
                if (isConnected[i][j] == 0) {
                    continue;
                }
                if (dsu.Find(i) == dsu.Find(j)) {
                    continue;
                }
                dsu.Union(i, j);
                --num_cicle;
            }
        }
        return num_cicle;
    }

private:
    struct DisjointSetUnion {
        DisjointSetUnion(int size) : parents(size, 0) {
            std::iota(parents.begin(), parents.end(), 0);
        }

        int Find(int index) {
            if (parents[index] != index) {
                parents[index] = Find(parents[index]);
            }
            return parents[index];
        }

        void Union(int index, int other_index) {
            parents[Find(index)] = Find(other_index);
        }

        std::vector<int> parents;
    };
};
