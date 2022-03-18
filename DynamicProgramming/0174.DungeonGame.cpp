class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon.front().empty()) {
            return 0;
        }
        const int m = dungeon.size();
        const int n = dungeon.front().size();
        std::vector<std::vector<int>> min_health(m+1, std::vector<int>(n+1, INT_MAX));
        min_health[m][n-1] = 1;
        min_health[m-1][n] = 1;
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                const int health = 
                    std::min(min_health[i][j+1], min_health[i+1][j]) - dungeon[i][j];
                min_health[i][j] = health <= 0 ? 1 : health;
            }
        }
        return min_health[0][0];
    }
};
