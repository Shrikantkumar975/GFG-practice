/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeSum(Node *root, int l, int r) {
    
    if (root == nullptr) return 0;
    
    // If root value is less than range
    // all nodes in its left subtree 
    // will be less than range
    if (root->data < l) {
        return nodeSum(root->right, l, r);
    }
    
    // If root value is greater than range.
    // all nodes in its right subtree 
    // will be greater than range
    else if (root->data > r) {
        return nodeSum(root->left, l, r);
    }
    
    // If root value lies in the range.
    int left = nodeSum(root->left, l, r);
    int right = nodeSum(root->right, l, r);
    
    return left + right + root->data;
}

};
