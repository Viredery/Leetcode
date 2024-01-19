class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid.front().size();
        std::vector<std::pair<int, int>> locations;
        std::vector<std::pair<int, int>> other_locations;
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (grid[i][j] != 1) {
                    continue;
                }
                if (locations.empty()) {
                    dfs(grid, i, j, &locations);
                } else {
                    dfs(grid, i, j, &other_locations);
                }
            }
        }

        int number = 0;
        while (true) {
            if (locations.size() > other_locations.size()) {
                std::swap(locations, other_locations);
            }
            std::vector<std::pair<int, int>> new_locations;
            for (const auto& [x, y] : locations) {
                for (const auto& [dx, dy] : DIRECTIONS) {
                    const int i = x + dx;
                    const int j = y + dy;
                    if (i < 0 || j < 0 || i >= m || j >= n) {
                        continue;
                    }
                    if (std::ranges::find(other_locations, std::make_pair(i, j)) != other_locations.end()) {
                        return number;
                    }
                    if (grid[i][j] == -1) {
                        continue;
                    }
                    grid[i][j] = -1;
                    new_locations.push_back(std::make_pair(i, j));
                }
            }
            ++number;
            locations = std::move(new_locations);
        }
        return -1;
    }
private:
    constexpr inline static std::array<std::pair<int, int>, 4> DIRECTIONS = {
        std::make_pair(-1, 0), std::make_pair(1, 0), std::make_pair(0, -1), std::make_pair(0, 1)};

    void dfs(vector<vector<int>>& grid, int i, int j, std::vector<std::pair<int, int>>* locations) {
        const int m = grid.size();
        const int n = grid.front().size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1) {
            return;
        }
        grid[i][j] = -1;
        locations->push_back(std::make_pair(i, j));
        for (const auto& [dx, dy] : DIRECTIONS) {
            dfs(grid, i + dx, j + dy, locations);
        }
    }
};
