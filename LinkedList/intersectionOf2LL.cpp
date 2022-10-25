ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == nullptr or headB == nullptr) return nullptr;
    
    ListNode * c1 = headA;
    ListNode * c2 = headB;
    
    while(c1 != c2) {
        c1 = c1==NULL? headB : c1->next;
        c2 = c2==NULL? headA : c2->next;
    }
    
    return c1;
}