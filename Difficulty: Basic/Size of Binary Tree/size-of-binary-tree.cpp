/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int count=0;
  
    void dfs(Node *root){
        if(!root) return;
        
        count++;
        
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
    }
    
    int getSize(Node* root) {
        // code here
        dfs(root);
        
        return count;
    }
};