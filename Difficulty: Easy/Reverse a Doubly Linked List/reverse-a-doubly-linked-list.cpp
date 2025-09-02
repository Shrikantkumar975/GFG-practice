/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        
        if(!head) return head;
        
        Node* curr = head;
        Node* pre = nullptr;
        
        while(curr){
            curr->prev = curr->next;
            curr->next=pre;
            pre=curr;
            curr = curr->prev;
        }
        
        head = pre;
        return head;
        
    }
};