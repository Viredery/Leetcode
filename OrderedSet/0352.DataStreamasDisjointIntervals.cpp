class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        if (intervals_.empty()) {
            intervals_.insert({value, value});
            return;
        }
        auto next_iter = intervals_.upper_bound(value);
        auto prev_iter = intervals_.upper_bound(value);
        if (prev_iter == intervals_.begin()) {
            prev_iter = intervals_.end();
        } else if (prev_iter != intervals_.end()) {
            --prev_iter;
        } else {
            prev_iter = --intervals_.end();
        }

        if (prev_iter != intervals_.end() && prev_iter->second >= value) {
            // The value is always in the intervals.
            return;
        }

        bool need_merge_prev = false;
        if (prev_iter != intervals_.end() && prev_iter->second + 1 == value) {
            need_merge_prev = true;
        }
        bool need_merge_next = false;
        if (next_iter != intervals_.end() && next_iter->first == value + 1) {
            need_merge_next = true;
        }
        if (!need_merge_prev && !need_merge_next) {
            intervals_.insert({value, value});
        } else if (need_merge_prev && need_merge_next) {
            prev_iter->second = next_iter->second;
            intervals_.erase(next_iter);
        } else if (need_merge_prev) {
            prev_iter->second = value;
        } else {
            intervals_.insert({value, next_iter->second});
            intervals_.erase(next_iter);
        }
    }
    
    vector<vector<int>> getIntervals() {
        std::vector<std::vector<int>> intervals;
        for (const auto& [start, end] : intervals_) {
            intervals.push_back({start, end});
        }
        return intervals;
    }
private:
    std::map<int, int> intervals_;  // {start: end}
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
