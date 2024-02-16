class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto iter = events.lower_bound(start);
        if (iter != events.end() && !(iter->first >= end || iter->second <= start)) {
            return false;
        }
        if (!events.empty() && iter != events.begin()) {
            --iter;
            if (!(iter->first >= end || iter->second <= start)) {
                return false;
            }
        }
        events[start] = end;
        return true;
    }
private:
    std::map<int, int> events;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
