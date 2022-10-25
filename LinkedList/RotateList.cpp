int lenL(ListNode * head) {
    ListNode * curr = head;
    int count = 0;
    while(curr) {
        count++;
        curr = curr->next;
    }
    
    return count;
}

ListNode * getT(ListNode * head) {
    ListNode * t = head;
    while(t->next != NULL) {
        t = t->next;
    }
    
    return t;
}

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL or head->next == NULL) return head;
        int len = lenL(head);
        ListNode * curr = head;
        ListNode * tail = getT(head);
        
        k = k % len;
        
        if(k == 0) return head;
        
        int piv = len-k;
        int pos = 1;
        
        while(piv != pos) {
            pos++;
            curr = curr->next;
        }
        
        tail->next = head;
        head = curr->next;
        curr->next = NULL;
        
        return head;
    }
};