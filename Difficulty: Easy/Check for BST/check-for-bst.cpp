class Solution {
  public:
    bool helper(Node* root,long a,long b){
        if(!root){
            return true;
        }
        
        if(root->data <= a || root->data >=b){
            return false;
        }
        
        bool left = helper(root->left,a,root->data);
        bool right = helper(root->right,root->data,b);
        
        return left && right;
    }
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Your code here
        return helper(root,LONG_MIN,LONG_MAX);
    }
};