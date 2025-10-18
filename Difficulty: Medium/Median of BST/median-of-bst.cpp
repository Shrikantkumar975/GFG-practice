/*
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
    void getInorder(Node* node, vector<int>& traversal) {
    if (!node) return;
    
    getInorder(node->left, traversal);
    traversal.push_back(node->data);
    getInorder(node->right, traversal);
}

// Function to return Median of BST
int findMedian(Node* root) {
    vector<int> inorder;
    getInorder(root, inorder);
    int n = inorder.size();
    
    // n is even - 0 based indexing
    if (n % 2 == 0)
        return inorder[n/2-1];
        
    // n is odd - 0 based indexing
    else
        return inorder[n/2];
}
};