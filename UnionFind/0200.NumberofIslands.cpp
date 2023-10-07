class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid.front().empty()) {
            return 0;
        }
        const int m = grid.size();
        const int n = grid.front().size();

        int num_islands = 0;
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (grid[i][j] == '1') {
                    ++num_islands;
                }
            }
        }

        UnionFindSet uf{m * n};
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (grid[i][j] != '1' || visited[i][j]) {
                    continue;
                }
                const int pos = i * n + j;
                visited[i][j] = true;
                for (const auto& [dx, dy] : DIRECTION) {
                    const int x = i + dx;
                    const int y = j + dy;
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    }
                    if (grid[x][y] != '1' || visited[x][y]) {
                        continue;
                    }
                    const int other_pos = x * n + y;
                    if (uf.Find(pos) != uf.Find(other_pos)) {
                        uf.Union(pos, other_pos);
                        --num_islands;
                    }
                }
            }
        }

        return num_islands;
    }

private:
    static constexpr std::array<std::pair<int, int>, 4> DIRECTION = {
        std::make_pair(-1, 0), std::make_pair(0, -1), std::make_pair(1, 0), std::make_pair(0, 1)};

    struct UnionFindSet {
        UnionFindSet(int size) : parents(size, 0) {
            std::iota(parents.begin(), parents.end(), 0);
        }

        int Find(int index) {
            if (parents[index] != index) {
                parents[index] = Find(parents[index]);
            }
            return parents[index];
        }

        void Union(int one, int other) {
            parents[Find(one)] = Find(other);
        }

        std::vector<int> parents;
    };
};
