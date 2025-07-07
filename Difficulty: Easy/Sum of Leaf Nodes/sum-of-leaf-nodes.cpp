/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.
class Solution {
  public:
  
    void helper(Node* root,int &sum){
        if(root == nullptr) return;
        
        if(root->left == nullptr && root->right == nullptr) sum+=root->data;
        
        helper(root->left,sum);
        helper(root->right,sum);
    }
  
    int leafSum(Node* root) {
        // code here
        int sum = 0;
        
        helper(root,sum);
        
        return sum;
    }
};