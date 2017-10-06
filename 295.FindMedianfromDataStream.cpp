class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (minQueue.empty()) {
            minQueue.push(num);
            return;
        }
        if (minQueue.size() > maxQueue.size()) {
            if (minQueue.top() < num) {
                maxQueue.push(minQueue.top());
                minQueue.pop();
                minQueue.push(num);
            } else {
                maxQueue.push(num);
            }
        } else {
            if (maxQueue.top() > num) {
                minQueue.push(maxQueue.top());
                maxQueue.pop();
                maxQueue.push(num);
            } else {
                minQueue.push(num);
            }
        }
    }
    
    double findMedian() {
        if (minQueue.size() > maxQueue.size())
            return minQueue.top();
        return ((double)minQueue.top() + (double)maxQueue.top()) / 2.0;
    }
private:
    priority_queue<int, std::vector<int>, std::greater<int>> minQueue;
    priority_queue<int, std::vector<int>, std::less<int>> maxQueue;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */