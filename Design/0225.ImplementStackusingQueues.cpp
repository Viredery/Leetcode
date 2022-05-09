class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        const int size = que.size();
        for (int i = 0; i + 1 < size; ++i) {
            que.push(que.front());
            que.pop();
        }
        int top = que.front();
        que.pop();
        return top;
    }
    
    int top() {
        const int size = que.size();
        int top = 0;
        for (int i = 0; i != size; ++i) {
            top = que.front();
            que.push(que.front());
            que.pop();
        }
        return top;
    }
    
    bool empty() {
        return que.empty();
    }
private:
    std::queue<int> que;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
