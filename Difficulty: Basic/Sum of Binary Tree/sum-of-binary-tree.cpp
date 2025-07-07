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
  
    void helper(Node* root,int &count){
        if(root == nullptr) return;

        count+=root->data;
        helper(root->left,count);
        helper(root->right,count);
    }
    
    int sumBT(Node* root) {
        int count =0;
        helper(root,count);
        return count;
    }
};