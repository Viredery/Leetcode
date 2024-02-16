class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        event_states[startTime]++;
        event_states[endTime]--;
        int overlapped_events = 0;
        int max_overlapped_events = 0;
        for (const auto& [_, cnt] : event_states) {
            overlapped_events += cnt;
            max_overlapped_events = std::max(max_overlapped_events, overlapped_events);
        }
        return max_overlapped_events;
    }
private:
    std::map<int, int> event_states;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
