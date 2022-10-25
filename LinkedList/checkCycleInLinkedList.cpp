bool hasCycle(ListNode *head) {
    if(head == nullptr or head->next == nullptr) return false;
    ListNode * fast = head;
    ListNode * slow = head;
    
    while(fast != NULL and fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }
    
    return false;
}