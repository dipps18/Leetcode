class MedianFinder {
public:
    //Every element in this heap should be greater than elements in the max heap;
    priority_queue <int, vector<int>, greater<int>> large; 
    priority_queue<int> small;
    MedianFinder() {
    }
    
    void addNum(int num) {
        small.push(num);
        if(!small.empty() && !large.empty() && small.top() > large.top())
        {
            small.pop();
            int val = large.top();
            large.pop();
            small.push(val);
            large.push(num);
        }
        if(small.size() > large.size() + 1)
        {
            int val = small.top();
            small.pop();
            large.push(val);
        }
    }

    double findMedian() {
        if((large.size() + small.size()) % 2 != 0) 
            return small.top();
        return (large.top() + small.top()) / 2.0; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */