// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/
class Solution {
  public:
    struct Node* partition(struct Node* head, int x) {
        // code here
        Node* left = new Node(0);
        Node* right = new Node(0);
        Node* equal = new Node(0);
        
        Node* ltail = left;
        Node* rtail = right;
        Node* etail = equal;
        
        while(head){
            if(head->data < x){
                ltail->next = head;
                ltail = ltail->next;
            }else if(head->data>x){
                rtail->next = head;
                rtail= rtail->next;
            }else{
                etail->next = head;
                etail=etail->next;
            }
            head = head->next;
        }
        
        ltail->next = equal->next;
        
        etail->next= right->next;
        rtail->next= nullptr;
        return left->next;
        
    }
};