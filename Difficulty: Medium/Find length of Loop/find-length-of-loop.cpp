/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        if(head == nullptr) return 0;
        
        Node* slow = head;
        Node* fast = head;
        
        int len =0;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow == fast){
                do{
                    len++;
                    slow = slow->next;
                }while(slow!=fast);
                break;
            }
        }
        
        return len;
    }
};