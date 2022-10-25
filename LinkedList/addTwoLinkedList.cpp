ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode * d = new ListNode();
    ListNode * prev = d;
    ListNode * c1 = l1;
    ListNode * c2 = l2;
    
    int carry = 0;
    while(c1 or c2 or carry) {
        int sum = 0;
        
        if(c1) {
            sum += c1->val;
            c1 = c1->next;
        }
        
        if(c2) {
            sum += c2->val;
            c2 = c2->next;
        }
            
        sum += carry;
        
        int num = sum % 10;
        carry = sum/10;
        
        prev->next = new ListNode(num);
        prev = prev->next;

    }
    
    return d->next;
}