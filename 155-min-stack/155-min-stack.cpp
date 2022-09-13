class MinStack {
    vector<int> myStack;
    vector<int> minStack;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(minStack.empty() || minStack.back() > val)
            minStack.push_back(val);
        else
            minStack.push_back(minStack.back());
        myStack.push_back(val);

    }
    
    void pop() {
        myStack.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        return myStack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */