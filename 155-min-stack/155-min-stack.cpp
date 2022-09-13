class Node
{

    public:
        int elem;
        int min;
        Node* prev = nullptr;
        Node(){}
        Node(int elem, int min, Node* prev)
        {
            this->elem = elem;
            this->min = min;
            this->prev = prev;
        }
};
class MinStack {
public:
    Node* minStack = nullptr;
    MinStack() {
    }
    
    void push(int val) {
        if(minStack == nullptr)
            minStack = new Node(val, val, nullptr);
        else
            minStack = new Node(val, min(val, minStack->min), minStack);
    }
    
    void pop() {
        minStack = minStack->prev;
    }
    
    int top() {
        return minStack->elem;
    }
    
    int getMin() {
        return minStack->min;
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