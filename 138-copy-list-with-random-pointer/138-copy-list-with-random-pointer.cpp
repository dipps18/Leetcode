/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*, Node*> oldToCopy;
        Node* cur = head;
        Node* copy = new Node(head->val);
        while(cur)
        {
            oldToCopy[cur] = copy;
            if(cur->next)
                copy->next = new Node(cur->next->val);
            copy = copy->next;
            cur = cur->next;
        }
        for(auto [old, copy] : oldToCopy)
        {
            if(old->random)
                copy->random = oldToCopy[old->random];
        }
        return oldToCopy[head];
    }
};