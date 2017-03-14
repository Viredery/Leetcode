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
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty())
            return {};
        std::sort(intervals.begin(), intervals.end(),
                [](Interval l, Interval r) { return l.start < r.start; });
        int i = 0;
        while (i < intervals.size() - 1) {
            if (intervals[i].end >= intervals[i+1].start) {
                intervals[i].end = intervals[i].end > intervals[i+1].end ? intervals[i].end : intervals[i+1].end;
                intervals.erase(intervals.begin() + i + 1);
            } else
                i++;
        }
        return intervals;
    }
};