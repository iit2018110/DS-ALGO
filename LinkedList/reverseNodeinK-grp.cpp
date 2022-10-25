ListNode* reverseKGroup(ListNode* head, int k) {
    if(head->next == NULL or k == 1) return head;
    
    oh = NULL, ot = NULL, th = NULL, tt = NULL;
    
    int len = findL(head);
    
    ListNode * curr = head;
    
    while(len >= k) {
        th = NULL, tt = NULL;
        int c = k;
        
        while(c--) {
            ListNode * nextN = curr->next;
            curr->next = NULL;
            addFirst(curr);
            
            curr = nextN;
        }
        
        if(oh == NULL) {
            oh = th;
            ot = tt;
        } else {
            ot->next = th;
            ot = tt;
        }

        len -= k;
    }
    
    ot->next = curr;
    
    return oh;
}