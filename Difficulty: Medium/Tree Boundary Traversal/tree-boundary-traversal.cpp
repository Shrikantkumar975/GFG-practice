/*
// Tree Node
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

bool isLeaf(Node* root) {
    if(!root) return false;
    return (root->left == NULL && root->right == NULL);
}

void leftBoundary(Node* root, vector<int>& res) {
    Node* cur = root;
    while(cur) {
        if(!isLeaf(cur)) res.push_back(cur->data);
        if(cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void rightBoundary(Node* root, vector<int>& res) {
    Node* cur = root;
    vector<int> temp;
    while(cur) {
        if(!isLeaf(cur)) temp.push_back(cur->data);
        if(cur->right) cur = cur->right;
        else cur = cur->left;
    }
    // Add in reverse order
    for(int i = temp.size()-1; i >= 0; i--) {
        res.push_back(temp[i]);
    }
}

void leafBoundary(Node* root, vector<int>& res) {
    if(!root) return;
    if(isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    leafBoundary(root->left, res);
    leafBoundary(root->right, res);
}

class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if(!root) return res;
        
        // Always push root node
        res.push_back(root->data);

        // Left boundary (excluding root and leaves)
        leftBoundary(root->left, res);

        // Leaf nodes
        leafBoundary(root->left, res);
        leafBoundary(root->right, res);

        // Right boundary (excluding root and leaves)
        rightBoundary(root->right, res);

        return res;
    }
};
