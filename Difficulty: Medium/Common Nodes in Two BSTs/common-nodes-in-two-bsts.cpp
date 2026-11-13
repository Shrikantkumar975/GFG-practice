
class Solution {
public:
    void inorder(Node* root, vector<int>& arr) {
        if (root == nullptr) return;

        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    vector<int> findCommon(Node* r1, Node* r2) {
        vector<int> a, b, ans;

        // Get sorted elements from both BSTs
        inorder(r1, a);
        inorder(r2, b);

        int i = 0, j = 0;

        // Two pointer approach
        while (i < a.size() && j < b.size()) {

            if (a[i] == b[j]) {
                ans.push_back(a[i]);
                i++;
                j++;
            }
            else if (a[i] < b[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return ans;
    }
};
