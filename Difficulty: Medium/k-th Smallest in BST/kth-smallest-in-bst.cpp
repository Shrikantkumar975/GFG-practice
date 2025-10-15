/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int kthSmallest(Node* root, int k) {
    int count = 0;

    Node* curr = root;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            count++;
            if (count == k) return curr->data;
            curr = curr->right;
        } else {
            // Find the inorder predecessor of curr
            Node* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            // Make curr the right child of its inorder predecessor
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } else {
                count++;
                if (count == k) return curr->data;

                // Revert the changes made in the tree structure
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }
    return -1;
}

};