class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<std::vector<int>> inserted_intervals;
        for (const auto& interval : intervals) {
            if (newInterval.empty() || interval[1] < newInterval[0]) {
                inserted_intervals.push_back(interval);
            } else if (interval[0] > newInterval[1]) {
                inserted_intervals.push_back(newInterval);
                inserted_intervals.push_back(interval);
                newInterval.clear();
            } else {
                newInterval[0] = std::min(interval[0], newInterval[0]);
                newInterval[1] = std::max(interval[1], newInterval[1]);
            }
        }
        if (!newInterval.empty()) {
            inserted_intervals.push_back(newInterval);
        }
        return inserted_intervals;
    }
};
