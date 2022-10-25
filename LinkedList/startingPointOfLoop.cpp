ListNode * checkCycle(ListNode * head) {    
    ListNode * fast = head;
    ListNode * slow = head;
    
    while(fast != NULL and fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return fast;
    }
    
    return NULL;
}

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return nullptr;
        
        ListNode * p = checkCycle(head);
        if(p == nullptr) return nullptr;
        
        ListNode * q = head;
        
        while(p!=q) {
            p = p->next;
            q = q->next;
        }
        
        return p;
    }
};