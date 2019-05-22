class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        std::sort(intervals.begin(), intervals.end(),
            [](vector<int>& l, vector<int>& r) {return l[0] < r[0];}
        );
        for (auto& interval : intervals) {
            if (merged.empty() || merged.back()[1] < interval[0])
                merged.push_back(interval);
            else
                merged.back()[1] = std::max(merged.back()[1], interval[1]);
        }
        return merged;
    }
};
