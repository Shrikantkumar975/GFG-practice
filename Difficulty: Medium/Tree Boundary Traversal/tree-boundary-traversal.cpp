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

class Solution {
public:
    bool isLeaf(Node* node) {
        return !node->left && !node->right;
    }

    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) res.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addLeaves(Node* root, vector<int>& res) {
        if (!root) return;
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        addLeaves(root->left, res);
        addLeaves(root->right, res);
    }

    void addRightBoundary(Node* root, vector<int>& res) {
        Node* curr = root->right;
        vector<int> tmp;
        while (curr) {
            if (!isLeaf(curr)) tmp.push_back(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        reverse(tmp.begin(), tmp.end());
        res.insert(res.end(), tmp.begin(), tmp.end());
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->data);

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};
