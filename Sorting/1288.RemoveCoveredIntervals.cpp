class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](auto& l, auto& r) {
            return l[0] == r[0] ? l[1] > r[1] : l[0] < r[0];
        });
        int num_removed = 0;
        int cur_idx = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[cur_idx][1] >= intervals[i][1]) {
                ++num_removed;
                continue;
            }
            cur_idx = i;
        }
        return static_cast<int>(intervals.size()) - num_removed;
    }
};
