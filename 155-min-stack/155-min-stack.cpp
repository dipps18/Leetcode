class Node
{
    public:
        int elem;
        int min;
        Node* next = nullptr;
        Node* prev = nullptr;
        Node(){}
        Node(int elem)
        {
            this->elem = elem;
        }
};
class MinStack {
public:
    Node* minStack = nullptr;
    MinStack() {
    }
    
    void push(int val) {
        if(minStack == nullptr)
        {
            minStack = new Node(val);
            minStack->elem = val;
            minStack->min = val;
        }
        else
        {
            minStack->next = new Node(val);
            minStack->next->prev = minStack;
            minStack = minStack->next;
            minStack->min = min(val, minStack->prev->min);
        }
    }
    
    void pop() {
        minStack = minStack->prev;
        if(minStack) minStack->next = nullptr;
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