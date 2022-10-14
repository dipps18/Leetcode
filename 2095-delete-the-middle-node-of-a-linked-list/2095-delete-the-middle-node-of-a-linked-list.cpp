/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* p = head, *fp = head;
        if(!head->next) return nullptr;
        while(fp && fp->next)
        {
            fp = fp->next->next;
            p = p->next;
        }
        if(!p->next) 
        {
            head->next = nullptr;
            return head;
        }
        p->val = p->next->val;
        p->next = p->next->next;
        return head;
    }
};