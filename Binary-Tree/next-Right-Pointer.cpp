Node* connect(Node* root) {
    Node* nextLevelLeftMostDummy = new Node(-1);
    Node* curr = root, *prev;
    
    while(curr) {
        prev = nextLevelLeftMostDummy;
        
        while(curr) {
            if(curr->left) {
                prev->next = curr->left;
                prev = prev->next;
            }
            
            if(curr->right) {
                prev->next = curr->right;
                prev = prev->next;
            }
            
            curr = curr->next;
        }
        
        curr = nextLevelLeftMostDummy->next;
        nextLevelLeftMostDummy->next = NULL;
    }
    
    return root;
}