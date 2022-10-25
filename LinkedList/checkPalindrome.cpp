ListNode * reverseList(ListNode * head) {
    ListNode * curr = head;
    ListNode * prev = nullptr;
    
    while(curr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    
    return prev;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* d = new ListNode();
        d->next = head;
        
        ListNode * fast = d, * slow = d;
        
        while(fast != NULL and fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow->next = reverseList(slow->next);
        
        slow = slow->next;
        
        ListNode * p = head;
        
        while(slow!=NULL) {
            if(p->val != slow->val) return false;
            p = p->next;
            slow = slow->next;
        }
        
        return true;
    }
};