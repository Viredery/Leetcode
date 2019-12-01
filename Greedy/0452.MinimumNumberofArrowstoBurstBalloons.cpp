class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int res = 0;
        int l = 0;
        while (l < points.size()) {
            int start = points[l][0], end = points[l][1];
            int r = l + 1;
            while (r < points.size()) {
                if (points[r][0] > end)
                    break;
                start = max(start, points[r][0]);
                end = min(end, points[r][1]);
                r++;
            }
            res++;
            l = r;
        }
        return res;
    }
};
