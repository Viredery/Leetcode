class Solution {
public:   
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int h = matrix.size();
        if (h == 0) return 0;
        int w = matrix[0].size();
        
        # init
        for (int _ = 0; _ != h; _++)
            cache.push_back(vector<int>(w, 0));
        
        int longestLen = 0;
        # dfs
        for (int i = 0; i != h; i++)
            for (int j = 0; j != w; j++)
                longestLen = std::max(longestLen, dfs(matrix, i, j, h, w));
        
        # free
        cache.clear();

        return longestLen;
    }
private:
    std::vector<std::vector<int>> cache;
    std::vector<std::pair<int, int>> direction{{0,1}, {1,0}, {0,-1}, {-1, 0}};
    
    int dfs(const std::vector<std::vector<int>>& matrix, int i, int j, int h, int w) {
        if (cache[i][j] != 0)
            return cache[i][j];
        int longestLen = 1;
        for (auto dir : direction) {
            int y = i + dir.first, x = j + dir.second;
            if (y < h && y >= 0 && x < w && x >= 0 && matrix[y][x] > matrix[i][j])
                longestLen = std::max(longestLen, 1 + dfs(matrix, y, x, h, w));
        }
        cache[i][j] = longestLen;
        return longestLen;
    }
};
