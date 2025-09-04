class Solution {
  public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;  // edge case
        
        // Dummy heads
        Node* zeroHead = new Node(-1);
        Node* oneHead  = new Node(-1);
        Node* twoHead  = new Node(-1);
        
        Node* zeroTail = zeroHead;
        Node* oneTail  = oneHead;
        Node* twoTail  = twoHead;
        
        Node* temp = head;
        
        // Distribute nodes into three lists
        while (temp) {
            if (temp->data == 0) {
                zeroTail->next = temp;
                zeroTail = zeroTail->next;
            } 
            else if (temp->data == 1) {
                oneTail->next = temp;
                oneTail = oneTail->next;
            } 
            else {
                twoTail->next = temp;
                twoTail = twoTail->next;
            }
            temp = temp->next;
        }
        
        // Connect three lists
        zeroTail->next = (oneHead->next) ? oneHead->next : twoHead->next;
        oneTail->next = twoHead->next;
        twoTail->next = nullptr;
        
        // New head
        Node* newHead = zeroHead->next;
        
        // Free dummy nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return newHead;
    }
};
