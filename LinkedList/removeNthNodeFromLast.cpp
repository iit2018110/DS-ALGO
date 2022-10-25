ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* d = new ListNode();
    d->next = head;
    ListNode* fast = d;
    ListNode* slow = d;
    
    for(int i = 0; i < n; ++i) 
        fast = fast->next;
    
    while(fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    
    return d->next;
}