/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        int cn0 =0;
        int cn1 =0;
        int cn2=0;
        
        Node* temp = head;
        
        while(temp){
            if(temp->data == 0) cn0++;
            else if(temp->data == 1) cn1++;
            else cn2++;
            
            temp = temp->next;
        }
        
        temp = head;
        
        while(temp){
            if(cn0){
                temp->data = 0;
                cn0--;
            }else if(cn1){
                temp->data =1;
                cn1--;
            }else{
                temp->data =2;
                cn2--;
            }
            
            temp = temp->next;
        }
        
        return head;
    }
};