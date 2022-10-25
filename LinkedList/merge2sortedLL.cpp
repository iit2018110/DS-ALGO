ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;
    
    ListNode * d = new ListNode();
    ListNode * prev = d;
    ListNode *c1 = l1;
    ListNode *c2 = l2;
    
    while(c1 and c2) {
        if(c1->val <= c2->val) {
            prev->next = c1;
            prev = prev->next;
            c1 = c1->next;
        }
        else {
            prev->next = c2;
            prev = prev->next;
            c2 = c2->next;
        }
    }
    
    if(c1 == nullptr) prev->next = c2;
    if(c2 == nullptr) prev->next = c1;
    
    return d->next;
}