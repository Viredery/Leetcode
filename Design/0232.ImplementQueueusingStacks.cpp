class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        push_st.push(x);
    }
    
    int pop() {
        if (pop_st.empty()) {
            while (!push_st.empty()) {
                pop_st.push(push_st.top());
                push_st.pop();
            }
        }
        int top = pop_st.top();
        pop_st.pop();
        return top;
    }
    
    int peek() {
        if (pop_st.empty()) {
            while (!push_st.empty()) {
                pop_st.push(push_st.top());
                push_st.pop();
            }
        }
        int top = pop_st.top();
        return top;
    }
    
    bool empty() {
        return push_st.empty() && pop_st.empty();
    }
private:
    std::stack<int> push_st;
    std::stack<int> pop_st;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
