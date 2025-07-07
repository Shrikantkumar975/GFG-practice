/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
    
    void helper(Node* root,vector<int> &v){
        if(root==nullptr) return;
        
        if(root->left == nullptr && root->right == nullptr) v.push_back(root->data);
        
        helper(root->left,v);
        helper(root->right,v);
    }
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
        vector<int> v;
        helper(root,v);
        return v.size();
        
    }
};