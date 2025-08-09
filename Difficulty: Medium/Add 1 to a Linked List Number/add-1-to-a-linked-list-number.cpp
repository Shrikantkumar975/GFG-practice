/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev= nullptr;
        Node* nextNext= nullptr;
        
        while(curr){
            nextNext = curr->next;
            curr->next =prev ;
            prev = curr;
            curr = nextNext;
        }
        
        head = prev;
        return head;;
    }
    
    Node* addOne(Node* head) {
        // Your Code here
        int carry = 1;
        head = reverse(head);
        Node* temp = head;
        
        while(temp){
            temp->data+=carry;
            
            if(temp->data >= 10){
                temp->data = 0;
                carry =1;
            }else{
                carry = 0;
                break;
            }
            
            temp=temp->next;
        }
        
        if(carry == 1){
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode;
            head = reverse(head);
        }
        
        head = reverse(head);
        return head;
        // return head of list after adding one
    }
};