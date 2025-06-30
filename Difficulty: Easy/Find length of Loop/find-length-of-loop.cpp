/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node* slow = head;
        Node* fast = head;
        int count =0;

        while(fast && fast->next){
            slow=slow->next;
            fast = fast->next->next;

            if(slow == fast ){
                do{
                    slow=slow->next;
                    count++;
                }while(slow!=fast);
                return count;
            }
        }
        return count;
    }
};