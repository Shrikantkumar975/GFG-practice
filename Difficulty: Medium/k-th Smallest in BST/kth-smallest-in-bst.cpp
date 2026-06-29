/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int ans=-1;
    
    void inorder(Node* root, int &k){
        if(!root || ans!=-1) return;
        
        inorder(root->left,k);
        k-=1;
        if(k==0){
            ans = root->data;
            return;
        }
        inorder(root->right,k);
    }
    
    int kthSmallest(Node *root, int k) {
        inorder(root,k);
        
        return ans;
        
    }
};