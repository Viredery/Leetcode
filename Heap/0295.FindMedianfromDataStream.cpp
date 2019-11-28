class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (p.empty() || p.top() >= num)
            p.push(num);
        else
            q.push(num);
        
        if (p.size() < q.size()) {
            p.push(q.top());
            q.pop();
        } else if (p.size() > q.size() + 1) {
            q.push(p.top());
            p.pop();
        }
    }
    
    double findMedian() {
        if (p.size() > q.size())
            return p.top();
        return (p.top() + q.top()) / 2.0;
    }

private:
    priority_queue<int> p; // xiaoshulimiande zuidashu
    priority_queue<int, vector<int>, greater<int>> q;
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
