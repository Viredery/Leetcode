class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        std::sort(intervals.begin(), 
                  intervals.end(), 
                  [](auto& l, auto& r) { return l[0] < r[0]; });
        std::vector<std::vector<int>> merged_intervals;
        std::vector<int> current_interval{intervals.front()};
        for (int i = 1; i != intervals.size(); ++i) {
            if (intervals[i][0] <= current_interval[1]) {
                current_interval[1] = std::max(intervals[i][1], current_interval[1]);
                continue;
            }
            merged_intervals.push_back(std::move(current_interval));
            current_interval = intervals[i];
        }
        merged_intervals.push_back(std::move(current_interval));
        return merged_intervals;
    }
};
