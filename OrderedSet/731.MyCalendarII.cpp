class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        event_states[start]++;
        event_states[end]--;
        int overlapped_events = 0;
        for (const auto& [_, cnt] : event_states) {
            overlapped_events += cnt;
            if (overlapped_events >= 3) {
                event_states[start]--;
                event_states[end]++;
                return false;
            }
        }
        return true;
    }
private:
    std::map<int, int> event_states;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
