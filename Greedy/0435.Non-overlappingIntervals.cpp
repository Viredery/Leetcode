class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), 
                 intervals.end(), 
                 [](auto& l, auto& r) { return l[1] < r[1]; });
        int num_removed = 0;
        int current_end = std::numeric_limits<int>::lowest();
        for (const auto& interval : intervals) {
            if (interval[0] >= current_end) {
                current_end = interval[1];
                continue;
            }
            ++num_removed;
        }
        return num_removed;
    }
};
