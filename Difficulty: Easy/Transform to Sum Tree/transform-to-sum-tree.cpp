class Solution {
  public:
  
    int solve(Node* root){
        if(root == NULL){
            return 0;
        }
        
        // Store original value
        int oldValue = root->data;
        
        // Get sum from left and right subtree
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);
        
        // Update current node
        root->data = leftSum + rightSum;
        
        // Return total sum of original subtree
        return root->data + oldValue;
    }
  
    void toSumTree(Node *root) {
        solve(root);
    }
};