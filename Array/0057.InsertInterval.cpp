class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        
        int i = 0;
        while (i < intervals.size() && newInterval[0] > intervals[i][1])
            res.push_back(intervals[i++]);
        if (i == intervals.size()) {
            res.push_back(newInterval);
            return res;
        }
        int intervalStart = min(intervals[i][0], newInterval[0]);
        while (i < intervals.size() && newInterval[1] > intervals[i][1])
            i++;
        int intervalEnd = newInterval[1];
        if (i < intervals.size() && newInterval[1] >= intervals[i][0]) {
            intervalEnd = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back({intervalStart, intervalEnd});
        while (i < intervals.size())
            res.push_back(intervals[i++]);
        return res;
    }
};
