class Node
{
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    
    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    int curSize;
    Node* keyNode[2000001] = {nullptr};
    Node* head; //most recently used
    Node* tail; //least recently used
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
        curSize = 0;
    }
    
    int get(int key)
    {
        Node* temp = tail;
        if(!keyNode[key])
            return -1;     
        Node* node = keyNode[key];
        Node* tempPrev = node->prev;
        Node* tempNext = node->next;

        if(head != node)
        {
            if(tempPrev )
                tempPrev->next = tempNext;
            if(tempNext)
                tempNext->prev = tempPrev;
            if(tail == node)
                tail = tail->next;
            head->next = node;
            node->prev = head;
            head = node;
            node->next = nullptr;
        }
        return node->val;
    }
 

    
    void put(int key, int value) {
        Node* node;
        //if key found, replace the value with new value and call get to place it on the mru
        if(keyNode[key])
        {
            node = keyNode[key];
            node->val = value;
            get(key);
        }
        else
        {
            curSize++;
            node = new Node(key, value);
            keyNode[key] = node;
            
            //if there is no element
            if(!head)
            {
                head = node;
                tail = node;
            }
            else
            {
                head->next = node;
                node->prev = head;
                head = node;
            }
        }
        
        if(curSize > capacity)
        {
            keyNode[tail->key] = nullptr;
            tail = tail->next;
            tail->prev = nullptr;
            curSize--;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */