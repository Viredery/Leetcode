/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int start = newInterval.start, end = newInterval.end;
        if (0 == intervals.size())
            return {newInterval};
        int pos = 0;
        while (pos != intervals.size() && start > intervals[pos].end) {
            res.push_back(intervals[pos]);
            ++pos;
        }
        if (pos == intervals.size()) {
            res.push_back(newInterval);
            return res;
        }
        int newStart = start < intervals[pos].start ? start : intervals[pos].start;
        while (pos != intervals.size() && end >= intervals[pos].start) {
            ++pos;
        }
        int newEnd = end > intervals[pos - 1].end ? end : intervals[pos - 1].end;
        res.emplace_back(newStart, newEnd);
        while (pos != intervals.size()) {
            res.push_back(intervals[pos]);
            ++pos;
        }
        return res;
    }
};