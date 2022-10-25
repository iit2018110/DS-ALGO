void copyList(Node * head) {
    Node * curr = head;
    Node * nextN = NULL;
    
    while(curr) {
        nextN = curr->next;
        curr->next = new Node(curr->val);
        curr->next->next = nextN;
        
        curr = nextN;
    }
}

void copyRandomPointers(Node * head) {
    Node * curr = head;
    
    Node * Random;
    while(curr) {
        Random = curr->random;
        if(Random!=NULL) curr->next->random = Random->next;
        
        curr = curr->next->next;
    }
}

Node * deepCopyList(Node * head) {
    Node * h1 = head->next;
    Node * c1 = h1;
    Node * curr = head;
    
    while(curr) {
        curr->next = curr->next->next;
        curr = curr->next;
        
        if(c1->next) c1->next = c1->next->next;
        c1 = c1->next;
    }
    
    return h1;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        
        copyList(head);
        copyRandomPointers(head);
        return deepCopyList(head);
    }
};