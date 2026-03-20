class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        Node* curr = root;

        while (curr != NULL) {
            if (curr->data == key) {
                // Predecessor is the rightmost child of the left subtree
                if (curr->left) {
                    Node* temp = curr->left;
                    while (temp->right) temp = temp->right;
                    pre = temp;
                }
                // Successor is the leftmost child of the right subtree
                if (curr->right) {
                    Node* temp = curr->right;
                    while (temp->left) temp = temp->left;
                    suc = temp;
                }
                break;
            } 
            else if (curr->data < key) {
                // Current node is a potential predecessor
                pre = curr;
                curr = curr->right;
            } 
            else {
                // Current node is a potential successor
                suc = curr;
                curr = curr->left;
            }
        }
        return {pre, suc};
    }
};
