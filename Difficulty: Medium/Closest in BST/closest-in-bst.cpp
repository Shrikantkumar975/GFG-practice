
class Solution {
public:
    int minDiff(Node *root, int k) {
        int ans = INT_MAX;

        while (root != nullptr) {

            // Update minimum difference
            ans = min(ans, abs(root->data - k));

            // Exact match found
            if (ans == 0) {
                return 0;
            }

            // Move towards the possible closest value
            if (k < root->data) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }

        return ans;
    }
};
