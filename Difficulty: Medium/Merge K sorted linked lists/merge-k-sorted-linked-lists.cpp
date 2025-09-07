/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    
    Node* merge(Node* head1, Node* head2){
        Node* dummy = new Node(0);
        Node* tail = dummy;
        
        while(head1 && head2){
            if(head1->data<head2->data){
                tail->next=head1;
                tail = tail->next;
                head1=head1->next;
            }else{
                tail->next=head2;
                tail = tail->next;
                head2=head2->next;
            }
        }
        
        if(head1){
            tail->next = head1;
        }
        
        if(head2){
            tail->next = head2;
        }
        
        return dummy->next;
    }
    
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        Node* ansHead = arr[0];
        for(int i=1;i<arr.size();i++){
            ansHead = merge(ansHead,arr[i]);
        }
        
        return ansHead;
    }
};