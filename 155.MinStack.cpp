class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        stack.clear();
        minStored.clear();
    }
    
    void push(int x) {
        stack.push_back(x);
        minStored.push_back(minStored.empty() ? x : min(minStored.back(), x));
    }
    
    void pop() {
        stack.pop_back();
        minStored.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStored.back();
    }

private:
    vector<int> stack;
    vector<int> minStored;
};