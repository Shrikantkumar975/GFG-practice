class Solution {
  public:
  
    struct Info {
        int size;
        int minVal;
        int maxVal;
        bool isBST;
    };
    
    int ans = 0;
    
    Info solve(Node* root) {
        // Base case
        if (root == NULL) {
            return {0, INT_MAX, INT_MIN, true};
        }
        
        // Left and Right
        Info left = solve(root->left);
        Info right = solve(root->right);
        
        Info curr;
        curr.size = left.size + right.size + 1;
        
        // Check BST condition
        if (left.isBST && right.isBST &&
            root->data > left.maxVal &&
            root->data < right.minVal) {
                
            curr.isBST = true;
            curr.minVal = min(root->data, left.minVal);
            curr.maxVal = max(root->data, right.maxVal);
            
            ans = max(ans, curr.size);
        }
        else {
            curr.isBST = false;
            curr.minVal = INT_MIN;
            curr.maxVal = INT_MAX;
        }
        
        return curr;
    }
    
    int largestBst(Node *root) {
        ans = 0;
        solve(root);
        return ans;
    }
};